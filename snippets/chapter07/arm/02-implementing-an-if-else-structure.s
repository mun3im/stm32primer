; STM32 Primer, Chapter 7 -- Implementing an If-Else Structure
; Source: chapter7.tex, line 337. Extracted as printed in the book; it may be a fragment, not a complete program.

                CMP   R0, R1          ; Compare a (R0) and b (R1)
                BNE   else_block      ; If a != b, select the else-block

                ; If-block: a == b
                MOV   R2, #1          ; x = 1
                B     endif           ; Skip the else-block

else_block
                ; Else-block: a != b
                MOV   R2, #2          ; x = 2

endif
                ; Program execution continues...
