; STM32 Primer, Appendix C -- Unsigned divide by 10: $q = x / 10$ and $r = x \bmod 10$
; Source: appendix.tex, line 636. Extracted as printed in the book; it may be a fragment, not a complete program.

; R0 = x (unsigned)
LDR   R12, =0xCCCCCCCD          ; magic multiplier
                                                        ; (2^35/10, rounded up)
UMULL R3, R2, R0, R12           ; R2:R3 = x * magic; R2 = high word
LSR   R2, R2, #3                ; R2 = q = x / 10 (total shift = 35)
ADD   R3, R2, R2, LSL #2        ; R3 = 5q
SUB   R3, R0, R3, LSL #1        ; R3 = x - 10q = r = x mod 10
