// STM32 Primer, Chapter 8 -- Experiment 5 --- Binary Counter on Four LEDs
// Source: chapter8.tex, line 386. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

void delay_ms(uint32_t ms) {
    volatile uint32_t count = ms * 1600;
    while (count > 0) { count--; }
}

int main(void) {
    RCC->AHB1ENR |= (1U << 1);              // GPIOB clock

    // Configure PB0..PB3 as outputs
    for (uint32_t pin = 0; pin < 4; pin++) {
        GPIOB->MODER &= ~(3U << (pin * 2));
        GPIOB->MODER |=  (1U << (pin * 2));
    }

    uint8_t count = 0;
    while (1) {
        // Write the low 4 bits of 'count' to PB0..PB3 atomically:
        // set the bits that are 1, reset the bits that are 0.
        GPIOB->BSRR = ((uint32_t)(count & 0x0F))
                    | ((uint32_t)(~count & 0x0F) << 16);
        count++;                            // wraps 15 to 0 on its own
        delay_ms(500);
    }
}
