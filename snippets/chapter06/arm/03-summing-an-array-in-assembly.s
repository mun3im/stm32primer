; STM32 Primer, Chapter 6 -- Summing an Array in Assembly
; Source: chapter6.tex, line 698. Extracted as printed in the book; it may be a fragment, not a complete program.

                LDR   R1, =array     ; base address
                MOV   R0, #0         ; sum = 0
                MOV   R2, #0         ; i = 0
loop
                LDR   R3, [R1, R2, LSL #2]  ; R3 = array[i]
                ADD   R0, R0, R3     ; sum += array[i]
                ADD   R2, R2, #1     ; i++
                CMP   R2, #10
                BLT   loop
