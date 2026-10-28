// STM32 Primer, Chapter 14
// Source: chapter14.tex, line 54. Extracted as printed in the book; it may be a fragment, not a complete program.

while (1) {
    if (msTicks >= next_sample) {
        next_sample += 100;
        take_sample();
    }
}
