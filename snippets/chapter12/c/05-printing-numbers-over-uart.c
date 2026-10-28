// STM32 Primer, Chapter 12 -- Printing Numbers Over UART
// Source: chapter12.tex, line 443. Extracted as printed in the book; it may be a fragment, not a complete program.

// Print an unsigned integer in decimal, without using printf
void uart_print_uint(uint32_t value) {
    char buf[11];
    int i = 0;

    if (value == 0) {
        uart_write('0');
        return;
    }
    while (value > 0) {          // least-significant digit first
        buf[i++] = '0' + (value % 10);
        value /= 10;
    }
    while (i > 0) {              // so print them in reverse
        uart_write((uint8_t)buf[--i]);
    }
}

// Print a 32-bit value in hexadecimal -- ideal for register contents
void uart_print_hex(uint32_t value) {
    const char *digits = "0123456789ABCDEF";
    uart_print("0x");
    for (int shift = 28; shift >= 0; shift -= 4) {
        uart_write((uint8_t)digits[(value >> shift) & 0xF]);
    }
}
