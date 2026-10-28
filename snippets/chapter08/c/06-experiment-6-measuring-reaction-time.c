// STM32 Primer, Chapter 8 -- Experiment 6 --- Measuring Reaction Time
// Source: chapter8.tex, line 424. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

void delay_ms(uint32_t ms) {
    volatile uint32_t count = ms * 1600;
    while (count > 0) { count--; }
}

int main(void) {
    RCC->AHB1ENR |= (1U << 0) | (1U << 2);
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));
    GPIOC->MODER &= ~(3U << (13 * 2));
    GPIOC->PUPDR &= ~(3U << (13 * 2));
    GPIOC->PUPDR |=  (1U << (13 * 2));

    volatile uint32_t reaction_ms;      // inspect this in the debugger

    while (1) {
        GPIOA->BSRR = (1U << (5 + 16)); // LED off
        delay_ms(2000);                 // wait before the cue
        GPIOA->BSRR = (1U << 5);        // LED on: react now

        reaction_ms = 0;
        while (GPIOC->IDR & (1U << 13)) {   // until the button goes LOW
            delay_ms(1);
            reaction_ms++;
        }
        GPIOA->BSRR = (1U << (5 + 16)); // acknowledge
        delay_ms(1000);
    }
}
