; STM32 Primer, Chapter 7 -- Nested subroutine call with LR preserved
; Source: chapter7.tex, line 1119. Extracted as printed in the book; it may be a fragment, not a complete program.

__main
                MOV R0, #5
                MOV R1, #10
                BL ProcessData
                ; R0 = 15
stop    B stop

ProcessData
                PUSH {LR} ; save return address
                BL AddNumbers
                POP {LR} ; restore return address
                BX LR
AddNumbers
                ADD R0, R0, R1
                BX LR
