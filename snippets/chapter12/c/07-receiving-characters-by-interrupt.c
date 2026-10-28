// STM32 Primer, Chapter 12 -- Receiving Characters by Interrupt
// Source: chapter12.tex, line 493. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

#define RX_BUF_SIZE 64
volatile uint8_t  rx_buf[RX_BUF_SIZE];
volatile uint8_t  rx_head = 0;
volatile uint8_t  rx_ready = 0;

void USART2_IRQHandler(void) {
    if (USART2->SR & (1U << 5)) {           // RXNE
        uint8_t c = USART2->DR;             // clears RXNE

        if (c == '\r' || rx_head >= RX_BUF_SIZE - 1) {
            rx_buf[rx_head] = '\0';
            rx_ready = 1;                   // a full line is ready
            rx_head  = 0;
        } else {
            rx_buf[rx_head++] = c;
        }
    }
}

int main(void) {
    USART2_init();
    USART2->CR1 |= (1U << 5);               // RXNEIE
    NVIC_EnableIRQ(USART2_IRQn);
    __enable_irq();

    uart_print("Type a line and press Enter.\r\n");

    while (1) {
        if (rx_ready) {
            rx_ready = 0;
            uart_print("You typed: ");
            uart_print((const char *)rx_buf);
            uart_print("\r\n");
        }
    }
}
