// STM32 Primer, Chapter 8 -- Experiment 1 --- Blinking an LED via ODR
// Source: chapter8.tex, line 229. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

void delay_ms(uint32_t ms) {
    volatile uint32_t count = ms * 1600;   // ~16 MHz calibration
    while (count > 0) { count--; }
}

int main(void) {
    RCC->AHB1ENR |= (1U << 0);          // 1. clock on for Port A

    GPIOA->MODER  &= ~(3U << (5 * 2));  // 2. PA5 mode: clear field
    GPIOA->MODER  |=  (1U << (5 * 2));  //    then set to output (01)
    GPIOA->OTYPER &= ~(1U << 5);        // 3. push-pull
    GPIOA->OSPEEDR &= ~(3U << (5 * 2)); //    low speed is fine for a LED
    GPIOA->PUPDR  &= ~(3U << (5 * 2));  //    no pull resistors needed

    while (1) {                         // 4. use it
        GPIOA->ODR ^= (1U << 5);        // toggle
        delay_ms(500);
    }
}
