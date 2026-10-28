// STM32 Primer, Chapter 11 -- Polling-Based ADC Reading
// Source: chapter11.tex, line 237. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

void adc_init(void) {
    // 1. Clocks: GPIOA on AHB1, ADC1 on APB2
    RCC->AHB1ENR |= (1U << 0);
    RCC->APB2ENR |= (1U << 8);

    // 2. PA0 to analog mode (11) -- disconnects digital input circuitry
    GPIOA->MODER |= (3U << (0 * 2));

    // 3. Sequence: one conversion, on channel 0
    ADC1->SQR1 &= ~(0xFU << 20);        // length = 1 conversion
    ADC1->SQR3 &= ~(0x1FU << 0);        // first conversion = channel 0

    // 4. Longest sampling time, for a high-impedance potentiometer
    ADC1->SMPR2 &= ~(7U << (0 * 3));
    ADC1->SMPR2 |=  (7U << (0 * 3));    // 111 = 480 cycles

    // 5. 12-bit resolution
    ADC1->CR1 &= ~(3U << 24);

    // 6. Single conversion, right aligned
    ADC1->CR2 &= ~(1U << 1);            // CONT = 0
    ADC1->CR2 &= ~(1U << 11);           // ALIGN = 0

    // 7. Power on the ADC
    ADC1->CR2 |= (1U << 0);             // ADON
}

uint32_t adc_read(void) {
    ADC1->CR2 |= (1U << 30);            // SWSTART: begin conversion

    while (!(ADC1->SR & (1U << 1))) {   // poll EOC
        // the CPU is blocked here for the whole conversion
    }

    return ADC1->DR;                    // reading clears EOC
}

int main(void) {
    adc_init();

    uint32_t raw;
    float voltage;

    while (1) {
        raw = adc_read();
        voltage = ((float)raw * 3.3f) / 4095.0f;   // Equation 11.4

        for (volatile int i = 0; i < 500000; i++); // crude pacing
    }
}
