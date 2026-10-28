; STM32 Primer, Chapter 7
; Source: chapter7.tex, line 904. Extracted as printed in the book; it may be a fragment, not a complete program.

__main
                MOV R0, #5
                MOV R1, #10
                BL ProcessData
                ; R0 = 15
stop    B stop

ProcessData
                BL AddNumbers ; overwrites LR
                BX LR

AddNumbers
                ADD R0, R0, R1
                BX LR
