// STM32 Primer, Chapter 9
// Source: chapter9.tex, line 24. Extracted as printed in the book; it may be a fragment, not a complete program.

while (1) {
    if (button_pressed()) {
        handle_press();
    }
    // Everything else the system must do has to fit here,
    // and must complete fast enough not to miss the next press.
}
