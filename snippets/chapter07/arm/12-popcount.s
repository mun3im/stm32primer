; STM32 Primer, Chapter 7
; Source: chapter7.tex, line 866. Extracted as printed in the book; it may be a fragment, not a complete program.

popcount
        MOV   R1, #0        ; count = 0
loop
        ANDS  R2, R0, #1    ; check bit 0
        ADD   R1, R1, R2    ; count += bit
        LSRS  R0, R0, #1    ; next bit; Z set when x reaches 0
        BNE   loop
        MOV   R0, R1        ; return the count
        BX    LR
