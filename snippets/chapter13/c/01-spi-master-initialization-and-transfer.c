// STM32 Primer, Chapter 13 -- SPI Master Initialization and Transfer
// Source: chapter13.tex, line 295. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

#define CS_LOW()   (GPIOB->BSRR = (1U << (12 + 16)))  // active low
#define CS_HIGH()  (GPIOB->BSRR = (1U << 12))         // deassert

void spi_init(void) {
    // 1. Clocks: GPIOB on AHB1, SPI2 on APB1
    RCC->AHB1ENR |= (1U << 1);
    RCC->APB1ENR |= (1U << 14);

    // 2. PB13, PB14, PB15 to alternate function mode (10)
    GPIOB->MODER &= ~((3U << (13*2)) | (3U << (14*2)) | (3U << (15*2)));
    GPIOB->MODER |=  ((2U << (13*2)) | (2U << (14*2)) | (2U << (15*2)));

    // 3. AF5 = SPI2. Pins 8-15 live in AFR[1], indexed as (pin - 8)*4
    GPIOB->AFR[1] &= ~((0xFU << (5*4)) | (0xFU << (6*4)) | (0xFU << (7*4)));
    GPIOB->AFR[1] |=  ((5U << (5*4)) | (5U << (6*4)) | (5U << (7*4)));

    // 4. PB12 as a plain output for chip select
    GPIOB->MODER &= ~(3U << (12*2));
    GPIOB->MODER |=  (1U << (12*2));
    CS_HIGH();                          // idle deasserted

    // 5. Configure SPI2: master, mode 3 (ADXL345), fPCLK/16
    SPI2->CR1 = 0;
    SPI2->CR1 |= (1U << 2);             // MSTR: master
    SPI2->CR1 |= (3U << 3);             // BR = 011: div by 16, 1 MHz
    SPI2->CR1 |= (1U << 1);             // CPOL = 1: SCK idles high
    SPI2->CR1 |= (1U << 0);             // CPHA = 1   (mode 3)
    SPI2->CR1 &= ~(1U << 7);            // MSB first
    SPI2->CR1 |= (1U << 9) | (1U << 8); // SSM, SSI: CS in software

    SPI2->CR1 |= (1U << 6);             // SPE: enable
}

// One byte out, one byte in -- a single exchange.
uint8_t spi_transfer(uint8_t out) {
    while (!(SPI2->SR & (1U << 1))) { } // wait for TXE
    *(volatile uint8_t *)&SPI2->DR = out;

    while (!(SPI2->SR & (1U << 0))) { } // wait for RXNE
    return *(volatile uint8_t *)&SPI2->DR;
}
