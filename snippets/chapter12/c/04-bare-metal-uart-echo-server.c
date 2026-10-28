// STM32 Primer, Chapter 12 -- Bare-Metal UART Echo Server
// Source: chapter12.tex, line 406. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

void uart_write(uint8_t ch) {
    while (!(USART2->SR & (1U << 7))) { }   // wait for TXE
    USART2->DR = ch;
}

uint8_t uart_read(void) {
    while (!(USART2->SR & (1U << 5))) { }   // wait for RXNE
    return USART2->DR;                       // reading clears RXNE
}

void uart_print(const char *s) {
    while (*s) {
        uart_write((uint8_t)*s++);
    }
}

int main(void) {
    USART2_init();

    uart_print("\r\n--- STM32 Bare-Metal UART Echo ---\r\n");
    uart_print("Type a character and it will be echoed:\r\n");

    while (1) {
        uint8_t c = uart_read();
        uart_write(c);
    }
}
