// STM32 Primer, Chapter 14 -- Integrated Sensor Monitor
// Source: chapter14.tex, line 199. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

/* ---------- Shared state (written by ISRs, read by main) ---------- */
volatile uint32_t msTicks     = 0;   // milliseconds since reset
volatile uint16_t adc_result  = 0;   // latest conversion
volatile uint8_t  adc_ready   = 0;   // set by ADC ISR
volatile uint8_t  button_flag = 0;   // set by EXTI ISR

/* ---------- Application state (main context only) ---------- */
static uint8_t show_millivolts = 0;  // display mode

/* =================== Interrupt handlers =================== */

void SysTick_Handler(void) {
    msTicks++;                          // its only job: advance the time
}

void ADC_IRQHandler(void) {
    if (ADC1->SR & (1U << 1)) {         // EOC
        adc_result = (uint16_t)ADC1->DR;   // reading DR clears EOC
        adc_ready  = 1;
    }
}

void EXTI15_10_IRQHandler(void) {
    static uint32_t last_press = 0;

    if (EXTI->PR & (1U << 13)) {
        EXTI->PR = (1U << 13);        // clear pending FIRST

        // Timestamp debouncing: no delay loop inside an ISR.
        if ((msTicks - last_press) > 200) {
            last_press  = msTicks;
            button_flag = 1;
        }
    }
}

/* =================== Peripheral setup =================== */

static void leds_init(void) {
    RCC->AHB1ENR |= (1U << 1);                  // GPIOB
    for (uint32_t pin = 0; pin < 4; pin++) {    // PB0..PB3 outputs
        GPIOB->MODER &= ~(3U << (pin * 2));
        GPIOB->MODER |=  (1U << (pin * 2));
    }
}

static void button_init(void) {
    RCC->AHB1ENR |= (1U << 2);                  // GPIOC
    GPIOC->MODER &= ~(3U << (13 * 2));          // PC13 input
    GPIOC->PUPDR &= ~(3U << (13 * 2));
    GPIOC->PUPDR |=  (1U << (13 * 2));          // pull-up

    RCC->APB2ENR |= (1U << 14);                 // SYSCFG
    SYSCFG->EXTICR[3] &= ~(0xFU << 4);
    SYSCFG->EXTICR[3] |=  (2U << 4);            // Port C -> EXTI13

    EXTI->FTSR |= (1U << 13);                   // falling edge
    EXTI->IMR  |= (1U << 13);                   // unmask

    NVIC_SetPriority(EXTI15_10_IRQn, 3);        // lowest urgency
    NVIC_EnableIRQ(EXTI15_10_IRQn);
}

static void adc_init(void) {
    RCC->AHB1ENR |= (1U << 0);                  // GPIOA
    RCC->APB2ENR |= (1U << 8);                  // ADC1

    GPIOA->MODER |= (3U << (0 * 2));            // PA0 analog

    ADC1->SQR1  &= ~(0xFU << 20);               // 1 conversion
    ADC1->SQR3  &= ~(0x1FU << 0);               // channel 0
    ADC1->SMPR2 &= ~(7U << 0);
    ADC1->SMPR2 |=  (7U << 0);                  // 480 cycles
    ADC1->CR1   |=  (1U << 5);                  // EOCIE
    ADC1->CR2   |=  (1U << 0);                  // ADON
    ADC1->CR2   |=  (6U << 24) | (1U << 28);    // TIM2 TRGO starts it
    NVIC_SetPriority(ADC_IRQn, 1);              // more urgent than button
    NVIC_EnableIRQ(ADC_IRQn);
}

static void uart_init(void) {
    RCC->AHB1ENR |= (1U << 1);                  // GPIOB
    RCC->APB2ENR |= (1U << 4);                  // USART1

    GPIOB->MODER &= ~((3U << (6*2)) | (3U << (7*2)));
    GPIOB->MODER |=  ((2U << (6*2)) | (2U << (7*2)));
    GPIOB->AFR[0] &= ~((0xFU << (6*4)) | (0xFU << (7*4)));
    GPIOB->AFR[0] |=  ((7U << (6*4)) | (7U << (7*4)));

    USART1->BRR  = (104U << 4) | 3U;            // 9600 from 16 MHz
    USART1->CR1 |= (1U << 3) | (1U << 2);       // TE, RE
    USART1->CR1 |= (1U << 13);                  // UE
}

/* =================== Helpers =================== */

static void uart_write(uint8_t c) {
    while (!(USART1->SR & (1U << 7))) { }       // TXE
    USART1->DR = c;
}

static void uart_print(const char *s) {
    while (*s) uart_write((uint8_t)*s++);
}

static void uart_print_uint(uint32_t v) {
    char buf[11];
    int i = 0;
    if (v == 0) { uart_write('0'); return; }
    while (v) { buf[i++] = '0' + (v % 10); v /= 10; }
    while (i)  { uart_write((uint8_t)buf[--i]); }
}

// Map a 12-bit reading onto a 4-LED bar, written atomically via BSRR.
static void leds_show_bar(uint16_t raw) {
    uint32_t level = (raw * 5U) / 4096U;        // 0..4 LEDs lit
    uint32_t pattern = (level >= 4) ? 0x0F : ((1U << level) - 1U);

    GPIOB->BSRR = (pattern & 0x0F) | ((~pattern & 0x0F) << 16);
}

/* =================== Main =================== */

int main(void) {
    __disable_irq();
    leds_init();
    button_init();
    adc_init();
    uart_init();
    SysTick_Config(16000000 / 1000);            // 1 ms tick
    __enable_irq();

    uart_print("\r\nSensor Monitor ready.\r\n");

    RCC->APB1ENR |= (1U << 0);                  // TIM2: 10 Hz trigger
    TIM2->PSC = 1599;                           // 16 MHz / 1600 = 10 kHz
    TIM2->ARR = 999;                            // 10 kHz / 1000 = 10 Hz
    TIM2->CR2 = (2U << 4);                      // MMS = 010: TRGO on update
    TIM2->CR1 |= (1U << 0);                     // start sampling

    while (1) {
        /* --- Task 1: none; TIM2 starts each conversion --- */


        /* --- Task 2: a result arrived --- */
        if (adc_ready) {
            uint16_t raw;

            __disable_irq();                // critical section:
            raw       = adc_result;         // copy the shared value
            adc_ready = 0;
            __enable_irq();

            leds_show_bar(raw);

            if (show_millivolts) {
                // Integer maths only: no FPU needed.
                uint32_t mv = ((uint32_t)raw * 3300U) / 4095U;
                uart_print("Level: ");
                uart_print_uint(mv);
                uart_print(" mV\r\n");
            } else {
                uart_print("Raw:   ");
                uart_print_uint(raw);
                uart_print("\r\n");
            }
        }

        /* --- Task 3: button pressed --- */
        if (button_flag) {
            button_flag = 0;
            show_millivolts = !show_millivolts;
            uart_print(show_millivolts ? "-> millivolts\r\n" : "-> raw\r\n");
        }
    }
}
