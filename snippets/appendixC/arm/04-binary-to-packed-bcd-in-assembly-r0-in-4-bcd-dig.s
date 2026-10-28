; STM32 Primer, Appendix C -- Binary to packed BCD in assembly (R0 in, 4 BCD digits out in R0)
; Source: appendix.tex, line 701. Extracted as printed in the book; it may be a fragment, not a complete program.

bin2bcd PROC
        PUSH    {R4, R5}            ; R4, R5 are callee-saved (AAPCS)
        LDR     R12, =0xCCCCCCCD    ; magic multiplier for /10
        MOVS    R1, #0              ; packed BCD result
        MOVS    R2, #0              ; bit position of the current nibble
digit:
        UMULL   R3, R4, R0, R12     ; R4 = high word of x * magic
        LSRS    R4, R4, #3          ; R4 = q = x / 10
        ADD     R5, R4, R4, LSL #2  ; R5 = 5q
        SUB     R5, R0, R5, LSL #1  ; R5 = x - 10q = current digit
        LSL     R5, R5, R2          ; move the digit to its nibble
        ORR     R1, R1, R5          ; merge into the result
        MOV     R0, R4              ; x = q
        ADDS    R2, R2, #4          ; next nibble
        CMP     R2, #16             ; four digits done?
        BLO     digit
        MOV     R0, R1              ; return value
        POP     {R4, R5}
        BX      LR
        ENDP
