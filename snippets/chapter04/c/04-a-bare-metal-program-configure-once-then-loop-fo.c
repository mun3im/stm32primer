// STM32 Primer, Chapter 4 -- A bare-metal program: configure once, then loop forever
// Source: chapter4.tex, line 601. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

int main(void) {
    // ---- setup: runs exactly once, after reset ----
    //      enable clocks, configure pins and peripherals

    while (1) {
        // ---- loop: runs until power is removed ----
        //      read inputs, decide, drive outputs
    }
    // never reached
}
