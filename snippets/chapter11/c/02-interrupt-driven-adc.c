// STM32 Primer, Chapter 11 -- Interrupt-Driven ADC
// Source: chapter11.tex, line 301. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

volatile uint32_t adc_data = 0;      // volatile: shared with the ISR
volatile uint8_t  data_ready = 0;

void ADC_IRQHandler(void) {
    if (ADC1->SR & (1U << 1)) {      // EOC
        adc_data   = ADC1->DR;       // reading DR clears the flag
        data_ready = 1;              // minimal work in the ISR
    }
}

void adc_init_interrupt(void) {
    __disable_irq();

    RCC->AHB1ENR |= (1U << 0);
    RCC->APB2ENR |= (1U << 8);
    GPIOA->MODER |= (3U << (0 * 2));  // PA0 analog

    ADC1->SQR1 &= ~(0xFU << 20);
    ADC1->SQR3 &= ~(0x1FU << 0);

    ADC1->SMPR2 &= ~(7U << (0 * 3));
    ADC1->SMPR2 |=  (7U << (0 * 3));

    ADC1->CR1 |= (1U << 5);           // EOCIE: interrupt at end of conv.
    ADC1->CR2 |= (1U << 0);           // ADON

    NVIC_SetPriority(ADC_IRQn, 1);
    NVIC_EnableIRQ(ADC_IRQn);

    __enable_irq();
}

int main(void) {
    adc_init_interrupt();
    float voltage;

    while (1) {
        ADC1->CR2 |= (1U << 30);      // start a conversion

        while (!data_ready) {
            // real work happens here while the ADC converts
        }

        data_ready = 0;
        voltage = ((float)adc_data * 3.3f) / 4095.0f;
    }
}
