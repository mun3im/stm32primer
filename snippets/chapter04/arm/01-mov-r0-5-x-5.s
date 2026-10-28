; STM32 Primer, Chapter 4
; Source: chapter4.tex, line 57. Extracted as printed in the book; it may be a fragment, not a complete program.

MOV   R0, #5          ; x = 5
STR   R0, [SP, #0]    ; store x in its stack slot
MOV   R1, #10         ; y = 10
STR   R1, [SP, #4]    ; store y
LDR   R0, [SP, #0]    ; reload x
LDR   R1, [SP, #4]    ; reload y
ADD   R2, R0, R1      ; z = x + y  (the actual arithmetic)
STR   R2, [SP, #8]    ; store z
