// STM32 Primer, Chapter 8 -- Experiment 2 --- Blinking via Atomic BSRR Writes
// Source: chapter8.tex, line 256. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

void delay_ms(uint32_t ms) {
    volatile uint32_t count = ms * 1600;
    while (count > 0) { count--; }
}

int main(void) {
    RCC->AHB1ENR |= (1U << 0);
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));

    while (1) {
        GPIOA->BSRR = (1U << 5);         // LED ON, one atomic store
        delay_ms(500);
        GPIOA->BSRR = (1U << (5 + 16));  // LED OFF, one atomic store
        delay_ms(500);
    }
}
