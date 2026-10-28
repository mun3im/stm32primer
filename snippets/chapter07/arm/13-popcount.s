; STM32 Primer, Chapter 7
; Source: chapter7.tex, line 880. Extracted as printed in the book; it may be a fragment, not a complete program.

popcount
        MOV   R1, #0        ; count = 0
        CMP   R0, #0
        BEQ   done
loop
        ADD   R1, R1, #1    ; count++
        SUBS  R2, R0, #1    ; R2 = x - 1
        ANDS  R0, R0, R2    ; x &= (x - 1): clears lowest set bit
        BNE   loop
done
        MOV   R0, R1        ; return the count
        BX    LR
