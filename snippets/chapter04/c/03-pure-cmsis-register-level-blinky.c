// STM32 Primer, Chapter 4 -- Pure CMSIS Register-Level Blinky
// Source: chapter4.tex, line 550. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"  // Vendor CMSIS device header: register maps

// Crude delay. 'volatile' stops the optimizer removing this loop.
void delay_ms(uint32_t ms) {
    volatile uint32_t i;
    for (i = 0; i < (ms * 1600); i++) {
        // burn cycles
    }
}

int main(void) {
    // 1. Enable the AHB1 peripheral clock for GPIOA.
    //    Without this the port is unpowered: no effect, reads are 0.
    RCC->AHB1ENR |= (1U << 0);

    // 2. Configure PA5 as a general purpose output.
    //    Each pin owns 2 bits; pin 5 uses bits 11:10. Clear, then set.
    GPIOA->MODER &= ~(3U << (5 * 2)); // clear the field to 00
    GPIOA->MODER |=  (1U << (5 * 2)); // write 01: general output mode

    // 3. Push-pull output driver (0 = push-pull, the reset default).
    GPIOA->OTYPER &= ~(1U << 5);

    // 4. No pull-up, no pull-down: the pin is actively driven both ways.
    GPIOA->PUPDR &= ~(3U << (5 * 2));

    while (1) {
        GPIOA->ODR ^= (1U << 5);   // toggle the LED
        delay_ms(500);
    }
}
