// STM32 Primer, Chapter 10
// Source: chapter10.tex, line 328. Extracted as printed in the book; it may be a fragment, not a complete program.

void EXTI15_10_IRQHandler(void) {
static uint32_t last_press = 0;
if (EXTI->PR & (1U << 13)) {
        EXTI->PR = (1U << 13);
        if ((msTicks - last_press) > 20) {   // ignore bounces within 20 ms
                last_press = msTicks;
                button_event = 1;
        }
}
}
