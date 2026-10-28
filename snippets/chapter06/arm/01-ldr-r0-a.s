; STM32 Primer, Chapter 6
; Source: chapter6.tex, line 41. Extracted as printed in the book; it may be a fragment, not a complete program.

LDR   R0, =a
LDR   R0, [R0]     ; R0 = a
LDR   R1, =b
LDR   R1, [R1]     ; R1 = b
LDR   R2, =c
LDR   R2, [R2]     ; R2 = c
ADD   R3, R0, R1   ; R3 = a + b
SUB   R3, R3, R2   ; R3 = (a+b) - c
LDR   R4, =total
STR   R3, [R4]
