; STM32 Primer, Chapter 7 -- Polling a Status Bit
; Source: chapter7.tex, line 542. Extracted as printed in the book; it may be a fragment, not a complete program.

; R0 already holds the address of USART2->SR
wait
                LDR   R1, [R0]      ; read the status register
                TST   R1, #(1 << 7) ; test bit 7 (TXE)
                BEQ   wait          ; bit clear: not ready yet, keep polling
                                                        ; bit set: TXE is ready, continue
