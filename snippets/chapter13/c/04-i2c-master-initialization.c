// STM32 Primer, Chapter 13 -- I2C Master Initialization
// Source: chapter13.tex, line 668. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

void i2c_init(void) {
    // 1. Clocks: GPIOB on AHB1, I2C1 on APB1
    RCC->AHB1ENR |= (1U << 1);
    RCC->APB1ENR |= (1U << 21);

    // 2. PB8, PB9 to alternate function mode (10)
    GPIOB->MODER &= ~((3U << (8*2)) | (3U << (9*2)));
    GPIOB->MODER |=  ((2U << (8*2)) | (2U << (9*2)));

    // 3. OPEN-DRAIN. Without this the bus cannot work at all.
    GPIOB->OTYPER |= (1U << 8) | (1U << 9);

    // 4. AF4 = I2C1. Pins 8-15 live in AFR[1], indexed as (pin - 8)*4
    GPIOB->AFR[1] &= ~((0xFU << 0) | (0xFU << 4));
    GPIOB->AFR[1] |=  ((4U << 0) | (4U << 4));

    // 5. Configure I2C1 for 100 kHz standard mode from a 16 MHz PCLK1
    I2C1->CR1 |= (1U << 15);            // SWRST: reset the peripheral
    I2C1->CR1 &= ~(1U << 15);           // release the reset
    I2C1->CR2  = 16;                    // FREQ: PCLK1 in MHz
    I2C1->CCR  = 80;                    // 16 MHz / (2 x 100 kHz) = 80
    I2C1->TRISE = 17;                   // max rise time: 16 + 1
    I2C1->CR1 |= (1U << 0);             // PE: enable the peripheral
}
