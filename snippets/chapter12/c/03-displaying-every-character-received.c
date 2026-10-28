// STM32 Primer, Chapter 12 -- Displaying Every Character Received
// Source: chapter12.tex, line 353. Extracted as printed in the book; it may be a fragment, not a complete program.

int USART2_read(void) {
    while (!(USART2->SR & (1U << 5))) ;  // wait RXNE
    return USART2->DR;                   // reading clears RXNE
}

int main(void) {
    USART2_init();
    while (1) {
        int c = USART2_read();
        USART2_write(c);   // show what arrived
    }
}
