// STM32 Primer, Chapter 8 -- Experiment 3 --- Button Controls LED
// Source: chapter8.tex, line 283. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

int main(void) {
    RCC->AHB1ENR |= (1U << 0);          // GPIOA clock (LED)
    RCC->AHB1ENR |= (1U << 2);          // GPIOC clock (button)

    GPIOA->MODER &= ~(3U << (5 * 2));   // PA5 output
    GPIOA->MODER |=  (1U << (5 * 2));

    GPIOC->MODER &= ~(3U << (13 * 2));  // PC13 input (00)
    GPIOC->PUPDR &= ~(3U << (13 * 2));  // clear pull field
    GPIOC->PUPDR |=  (1U << (13 * 2));  // enable pull-up (01)

    while (1) {
        if (!(GPIOC->IDR & (1U << 13))) {
            GPIOA->BSRR = (1U << 5);        // pressed (LOW) -> LED on
        } else {
            GPIOA->BSRR = (1U << (5 + 16)); // released      -> LED off
        }
    }
}
