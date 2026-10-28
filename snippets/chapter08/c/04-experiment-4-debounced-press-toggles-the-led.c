// STM32 Primer, Chapter 8 -- Experiment 4 --- Debounced Press Toggles the LED
// Source: chapter8.tex, line 346. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

void delay_ms(uint32_t ms) {
    volatile uint32_t count = ms * 1600;
    while (count > 0) { count--; }
}

int button_pressed(void) {
    if (!(GPIOC->IDR & (1U << 13))) {   // candidate press detected
        delay_ms(20);                   // let the contacts settle
        if (!(GPIOC->IDR & (1U << 13))) // still pressed? then it is real
            return 1;
    }
    return 0;
}

int main(void) {
    RCC->AHB1ENR |= (1U << 0) | (1U << 2);
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));
    GPIOC->MODER &= ~(3U << (13 * 2));
    GPIOC->PUPDR &= ~(3U << (13 * 2));
    GPIOC->PUPDR |=  (1U << (13 * 2));

    while (1) {
        if (button_pressed()) {
            GPIOA->ODR ^= (1U << 5);            // toggle on each press
            while (!(GPIOC->IDR & (1U << 13))); // wait for release
            delay_ms(20);                       // debounce the release
        }
    }
}
