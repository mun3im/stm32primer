// STM32 Primer, Chapter 12 -- Sending a Fixed String Over UART
// Source: chapter12.tex, line 305. Extracted as printed in the book; it may be a fragment, not a complete program.

void USART2_write(int c) {
    while (!(USART2->SR & (1U << 7))) ;  // wait TXE
    USART2->DR = (c & 0xFF);
}

int main(void) {
    USART2_init();
    const char *msg = "Hello World!\r\n";
    while (*msg) {
        USART2_write(*msg++);
    }
    while (1) { }   // nothing left to do
}
