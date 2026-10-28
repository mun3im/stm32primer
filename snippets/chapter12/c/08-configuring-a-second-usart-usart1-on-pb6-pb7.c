// STM32 Primer, Chapter 12 -- Configuring a Second USART: USART1 on PB6/PB7
// Source: chapter12.tex, line 560. Extracted as printed in the book; it may be a fragment, not a complete program.

void USART1_init(void) {
    // 1. Clocks: GPIOB on AHB1, USART1 on APB2 -- not APB1
    RCC->AHB1ENR |= (1U << 1);          // GPIOBEN
    RCC->APB2ENR |= (1U << 4);          // USART1EN

    // 2. PB6 and PB7 to alternate function mode (10)
    GPIOB->MODER &= ~((3U << (6 * 2)) | (3U << (7 * 2)));
    GPIOB->MODER |=  ((2U << (6 * 2)) | (2U << (7 * 2)));

    // 3. Select AF7 (USART1). Pins 0-7 live in AFR[0], 4 bits per pin.
    GPIOB->AFR[0] &= ~((0xFU << (6 * 4)) | (0xFU << (7 * 4)));
    GPIOB->AFR[0] |=  ((7U << (6 * 4)) | (7U << (7 * 4)));

    // 4. Baud rate: 9600 @ 16 MHz, OVER8 = 0; same BRR as USART2
    USART1->BRR = (104U << 4) | 3U;     // 0x0683

    // 5. Frame format: 8 data bits, no parity, enable TX and RX
    USART1->CR1 = (1U << 3) | (1U << 2);   // TE | RE

    // 6. Enable the peripheral last
    USART1->CR1 |= (1U << 13);          // UE
}
