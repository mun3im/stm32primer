; STM32 Primer, Chapter 5 -- A Complete ARM Assembly Program
; Source: chapter5.tex, line 41. Extracted as printed in the book; it may be a fragment, not a complete program.

; Define register names and constants
VAL1    RN  R1              ; Define VAL1 as alias for R1
VAL2    RN  R2              ; Define VAL2 as alias for R2
SUM     RN  R3              ; Define SUM as alias for R3
MY_CONST EQU 0x25           ; EQU constant definition

        AREA MY_ASM_PROG, CODE, READONLY
        ENTRY               ; Program entry point
__main
        MOV  VAL1, #MY_CONST ; Load literal 0x25 into R1
        MOV  VAL2, #0x34    ; Load literal 0x34 into R2
        ADD  SUM, VAL1, VAL2 ; R3 = R1 + R2

HERE    B    HERE           ; Infinite loop to halt program
        END                 ; End of assembly file
