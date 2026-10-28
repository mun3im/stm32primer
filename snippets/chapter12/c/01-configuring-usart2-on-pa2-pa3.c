// STM32 Primer, Chapter 12 -- Configuring USART2 on PA2/PA3
// Source: chapter12.tex, line 262. Extracted as printed in the book; it may be a fragment, not a complete program.

void USART2_init(void) {
    // 1. Clocks: GPIOA on AHB1, USART2 on APB1
    RCC->AHB1ENR |= (1U << 0);          // GPIOAEN
    RCC->APB1ENR |= (1U << 17);         // USART2EN

    // 2. PA2 and PA3 to alternate function mode (10)
    GPIOA->MODER &= ~((3U << (2 * 2)) | (3U << (3 * 2)));
    GPIOA->MODER |=  ((2U << (2 * 2)) | (2U << (3 * 2)));

    // 3. Select AF7 (USART2). Pins 0-7 live in AFR[0], 4 bits per pin.
    GPIOA->AFR[0] &= ~((0xFU << (2 * 4)) | (0xFU << (3 * 4)));
    GPIOA->AFR[0] |=  ((7U << (2 * 4)) | (7U << (3 * 4)));

    // 4. Baud rate: 9600 from 16 MHz, OVER8 = 0
    USART2->BRR = (104U << 4) | 3U;     // 0x0683

    // 5. Frame format: 8 data bits, no parity, enable TX and RX
    USART2->CR1 = (1U << 3) | (1U << 2);   // TE | RE, M, PCE default 0

    // 6. Enable the peripheral last
    USART2->CR1 |= (1U << 13);          // UE
}
