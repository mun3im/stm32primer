; STM32 Primer, Chapter 7 -- Counting-Up Loop
; Source: chapter7.tex, line 633. Extracted as printed in the book; it may be a fragment, not a complete program.

        MOV   R0, #0          ; R0 = loop counter i = 0
loop_up
        ; ... Loop Body ...
        ADD   R0, R0, #1      ; Increment counter (i = i + 1)
        CMP   R0, #10         ; Compare counter with limit
        BLT   loop_up         ; If i < 10, branch back
