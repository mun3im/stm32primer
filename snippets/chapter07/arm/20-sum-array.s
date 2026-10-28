; STM32 Primer, Chapter 7
; Source: chapter7.tex, line 1272. Extracted as printed in the book; it may be a fragment, not a complete program.

sum_array
        PUSH  {R4, LR}          ; prologue: save callee-saved R4, LR
        MOV   R2, #0            ; total = 0 (R2:caller-saved scratch)
        MOV   R3, #0            ; i = 0
        CMP   R1, #0            ; is n <= 0?
        BLE   done              ; if so, skip the loop entirely
loop
        LDR   R4, [R0, R3, LSL #2]   ; R4 = data[i], scaled offset
        ADD   R2, R2, R4             ; total += R4
        ADD   R3, R3, #1             ; i++
        CMP   R3, R1                 ; i < n ?
        BLT   loop                   ; signed compare: i, n are int
done
        MOV   R0, R2            ; return value goes in R0
        POP   {R4, PC}          ; epilogue: restore R4 and return
