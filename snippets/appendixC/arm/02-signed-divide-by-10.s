; STM32 Primer, Appendix C -- Signed divide by 10 ($q = x / 10$, $R0 = x$)
; Source: appendix.tex, line 675. Extracted as printed in the book; it may be a fragment, not a complete program.

LDR   R12, =0x66666667          ; 2^34 / 10, rounded up
SMULL R3, R2, R0, R12           ; signed 64-bit product,
                                                        ; R2 = high word
ASR   R2, R2, #2                ; arithmetic shift (total 34)
SUB   R2, R2, R0, ASR #31       ; subtract -1 (that is, add 1)
                                                        ;   if x < 0
