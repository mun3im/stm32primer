// STM32 Primer, Chapter 14
// Source: chapter14.tex, line 67. Extracted as printed in the book; it may be a fragment, not a complete program.

void EXTI15_10_IRQHandler(void) {
    EXTI->PR = (1U << 13);      // clear the pending flag
    event_flag = 1;             // record what happened, do nothing slow
}

while (1) {
    if (event_flag) {
        event_flag = 0;
        handle_event();
    }
}
