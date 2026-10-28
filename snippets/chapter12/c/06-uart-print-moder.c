// STM32 Primer, Chapter 12
// Source: chapter12.tex, line 474. Extracted as printed in the book; it may be a fragment, not a complete program.

uart_print("MODER = ");
uart_print_hex(GPIOA->MODER);
uart_print("\r\n");

uart_print("ADC raw = ");
uart_print_uint(adc_read());
uart_print("\r\n");
