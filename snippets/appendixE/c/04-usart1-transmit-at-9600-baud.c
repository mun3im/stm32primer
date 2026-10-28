// STM32 Primer, Appendix E -- USART1 transmit at 9600 baud
// Source: appendix.tex, line 1502. Extracted as printed in the book; it may be a fragment, not a complete program.

void uart1_init(void)
{
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_USART1EN;

        GPIOA->CRH = (GPIOA->CRH & ~((0xFU << 4U) | (0xFU << 8U)))
        | (0xBU << 4U)                // PA9  : AF push-pull
        | (0x4U << 8U);               // PA10 : floating input

        USART1->BRR = SystemCoreClock / 9600U;   // APB2 clock = HCLK
        USART1->CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
}

void uart1_putc(char c)
{
        while ((USART1->SR & USART_SR_TXE) == 0U) { }
        USART1->DR = (uint8_t)c;
}
