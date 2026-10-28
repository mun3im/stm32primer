// STM32 Primer, Chapter 4
// Source: chapter4.tex, line 148. Extracted as printed in the book; it may be a fragment, not a complete program.

typedef struct {
    __IO uint32_t MODER;   // Off. 0x00: GPIO Mode Reg
    __IO uint32_t OTYPER;  // Off. 0x04: GPIO Output Type Reg
    __IO uint32_t OSPEEDR; // Off. 0x08: GPIO Output Speed Reg
    __IO uint32_t PUPDR;   // Off. 0x0C: GPIO Pull-up/Pull-down Reg
    __IO uint32_t IDR;     // Off. 0x10: GPIO Input Data Reg
    __IO uint32_t ODR;     // Off. 0x14: GPIO Output Data Reg
    __IO uint32_t BSRR;    // Off. 0x18: GPIO Bit Set/Reset Reg
    __IO uint32_t LCKR;    // Off. 0x1C: GPIO Configuration Lock Reg
    __IO uint32_t AFR[2];  // Off. 0x20-0x24: Alt. Function Reg
} GPIO_TypeDef;
