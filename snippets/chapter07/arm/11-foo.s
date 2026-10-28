; STM32 Primer, Chapter 7
; Source: chapter7.tex, line 843. Extracted as printed in the book; it may be a fragment, not a complete program.

foo
        LSLS  R0, R0, #1   ; a*2 (strength reduction, Chapter 6)
        ADDS  R0, R0, R1   ; +b
        BX    LR

; --- at the call site: y already in R0, z in R1 ---
        BL    foo
        MOVS  R4, R0       ; x = result
