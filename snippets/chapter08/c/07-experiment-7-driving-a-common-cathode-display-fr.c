// STM32 Primer, Chapter 8 -- Experiment 7 --- Driving a Common-Cathode Display from Port C
// Source: chapter8.tex, line 492. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

// Segment order in each bit: 0bXDPgfedcba (bit 0 = segment a)
static const uint8_t digit_pattern[16] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,  // 0-7
    0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71   // 8-F
};

int main(void) {
    RCC->AHB1ENR |= (1U << 2);              // GPIOC clock

    for (uint32_t pin = 0; pin < 8; pin++) { // PC0..PC7 as outputs
        GPIOC->MODER &= ~(3U << (pin * 2));
        GPIOC->MODER |=  (1U << (pin * 2));
    }

    uint8_t digit = 0;
    while (1) {
        GPIOC->ODR = digit_pattern[digit & 0x0F]; // write the pattern
        digit++;
        for (volatile uint32_t d = 0; d < 500000; d++);
    }
}
