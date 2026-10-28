// STM32 Primer, Chapter 9 -- Shared Interrupt Handler for PC13 and PB10
// Source: chapter9.tex, line 676. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

void EXTI15_10_IRQHandler(void) {
    if (EXTI->PR & (1U << 13)) {     // PC13?
        GPIOA->ODR ^= (1U << 5);
        EXTI->PR = (1U << 13);
    }

    if (EXTI->PR & (1U << 10)) {     // PB10?
        GPIOA->ODR ^= (1U << 4);
        EXTI->PR = (1U << 10);
    }
}

int main(void) {
    __disable_irq();

    RCC->AHB1ENR |= 0x07;                      // Ports A, B, C

    GPIOA->MODER &= ~((3U << 10) | (3U << 8)); // PA5, PA4 outputs
    GPIOA->MODER |=  ((1U << 10) | (1U << 8));

    GPIOC->MODER &= ~(3U << 26);               // PC13 input, pull-up
    GPIOC->PUPDR &= ~(3U << 26);
    GPIOC->PUPDR |=  (1U << 26);

    GPIOB->MODER &= ~(3U << 20);               // PB10 input, pull-up
    GPIOB->PUPDR &= ~(3U << 20);
    GPIOB->PUPDR |=  (1U << 20);

    RCC->APB2ENR |= (1U << 14);                // SYSCFG

    SYSCFG->EXTICR[3] &= ~(0xFU << 4);         // PC13 -> EXTI13
    SYSCFG->EXTICR[3] |=  (2U << 4);
    SYSCFG->EXTICR[2] &= ~(0xFU << 8);         // PB10 -> EXTI10
    SYSCFG->EXTICR[2] |=  (1U << 8);

    EXTI->FTSR |= (1U << 13) | (1U << 10);
    EXTI->IMR  |= (1U << 13) | (1U << 10);

    NVIC_EnableIRQ(EXTI15_10_IRQn);
    __enable_irq();

    while (1) { }
}
