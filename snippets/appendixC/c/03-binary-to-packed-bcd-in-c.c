// STM32 Primer, Appendix C -- Binary to packed BCD in C
// Source: appendix.tex, line 688. Extracted as printed in the book; it may be a fragment, not a complete program.

uint32_t bin_to_bcd(uint32_t x)     // x must be 0..9999
{
        uint32_t bcd = 0;
        for (uint32_t shift = 0; shift < 16; shift += 4) {
                bcd |= (x % 10U) << shift;  // lowest digit, its nibble
                x /= 10U;                   // discard that digit
        }
        return bcd;
}
