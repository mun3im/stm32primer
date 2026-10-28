; STM32 Primer, Chapter 7
; Source: chapter7.tex, line 1236. Extracted as printed in the book; it may be a fragment, not a complete program.

; Caller: a..d already in R0-R3; e goes on the stack
        SUB   SP, SP, #8   ; reserve 8 bytes: SP stays 8-byte aligned
        LDR   R12, =e_value ; R12 is scratch, so no register is lost
        LDR   R12, [R12]
        STR   R12, [SP]    ; the fifth argument, e, at [SP]
        BL    weighted_sum
        ADD   SP, SP, #8   ; caller releases what it reserved

weighted_sum
        ADD   R0, R0, R1   ; a + b
        ADD   R0, R0, R2   ; + c
        ADD   R0, R0, R3   ; + d
        LDR   R1, [SP]     ; fifth argument, e, read from the stack
        ADD   R0, R0, R1   ; + e
        BX    LR
