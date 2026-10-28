; STM32 Primer, Chapter 7 -- Implementing a Plain If Structure
; Source: chapter7.tex, line 235. Extracted as printed in the book; it may be a fragment, not a complete program.

        CMP   R0, R1          ; Compare a (R0) and b (R1)
        BNE   endif           ; If a != b, skip the if-block

        ; If-block: a == b
        MOV   R2, #1          ; x = 1

endif
        ; Program execution continues...
