; STM32 Primer, Chapter 7
; Source: chapter7.tex, line 591. Extracted as printed in the book; it may be a fragment, not a complete program.

                LDR   r1, =0x5555
                MOV   r0, #0       ; count = 0
loop
                AND   r2, r1, #1   ; check bit 0
                ADD   r0, r2       ; c++
                LSRS  r1, r1, #1   ; next bit
                BNE   loop
done
