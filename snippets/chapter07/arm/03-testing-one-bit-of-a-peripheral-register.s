; STM32 Primer, Chapter 7 -- Testing One Bit of a Peripheral Register
; Source: chapter7.tex, line 488. Extracted as printed in the book; it may be a fragment, not a complete program.

                LDR   R2, [R0]        ; read GPIOC->IDR
                TST   R2, #(1 << 13)  ; test bit 13 (sets Z if the bit is 0)
                BNE   endif           ; bit set (button released): skip

                ; if-block: button pressed (bit 13 reads 0)
                LDR   R3, [R1]
                ORR   R3, R3, #(1 << 5)
                STR   R3, [R1]        ; GPIOA->ODR |= (1 << 5)

endif
                ; Program execution continues...
