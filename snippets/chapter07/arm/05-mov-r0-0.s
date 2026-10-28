; STM32 Primer, Chapter 7
; Source: chapter7.tex, line 522. Extracted as printed in the book; it may be a fragment, not a complete program.

                MOV   r0, #0
                MOV   r1, #1
loop
                CMP   r1, #5        ; r1 holds i
                BGT   done                      ;done if i greater than 5
                ADD   r0, r0, r1
                ADD   r1, r1, #1
                B     loop
done
