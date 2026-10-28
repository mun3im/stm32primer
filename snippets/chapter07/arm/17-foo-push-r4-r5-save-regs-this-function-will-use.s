; STM32 Primer, Chapter 7
; Source: chapter7.tex, line 1190. Extracted as printed in the book; it may be a fragment, not a complete program.

foo             PUSH {R4, R5}    ; save regs this function will use
                MOV  R4, #0
                MOV  R5, #0xAB
                ADD  R4, R4, R5
                ...
                POP  {R4, R5}    ; restore their original values
                BX   LR
