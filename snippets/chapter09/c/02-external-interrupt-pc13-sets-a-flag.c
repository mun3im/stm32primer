// STM32 Primer, Chapter 9 -- External Interrupt: PC13 Sets a Flag
// Source: chapter9.tex, line 475. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

volatile uint8_t button_event = 0;   // shared with main() -> volatile

// The name must match the vector table symbol exactly.
void EXTI15_10_IRQHandler(void) {
    if (EXTI->PR & (1U << 13)) {     // was line 13 responsible?
        EXTI->PR = (1U << 13);       // clear pending by writing 1
        button_event = 1;            // main() does the real work
    }
}

int main(void) {
    __disable_irq();                        // none while configuring

    // GPIO
    RCC->AHB1ENR |= (1U << 0) | (1U << 2);  // Port A and Port C clocks

    GPIOA->MODER &= ~(3U << (5 * 2));       // PA5 output
    GPIOA->MODER |=  (1U << (5 * 2));

    GPIOC->MODER &= ~(3U << (13 * 2));      // PC13 input
    GPIOC->PUPDR &= ~(3U << (13 * 2));
    GPIOC->PUPDR |=  (1U << (13 * 2));      // pull-up: idles HIGH

    // Route: PC13 to EXTI13
    RCC->APB2ENR |= (1U << 14);
    SYSCFG->EXTICR[3] &= ~(0xFU << 4);
    SYSCFG->EXTICR[3] |=  (2U << 4);        // Port C

    // Trigger: falling edge (button press pulls the pin LOW)
    EXTI->RTSR &= ~(1U << 13);
    EXTI->FTSR |=  (1U << 13);
    EXTI->IMR  |=  (1U << 13);              // unmask

    // Enable: NVIC, then globally
    NVIC_SetPriority(EXTI15_10_IRQn, 2);
    NVIC_EnableIRQ(EXTI15_10_IRQn);
    __enable_irq();

    while (1) {
        if (button_event) {
            button_event = 0;
            GPIOA->ODR ^= (1U << 5);        // the real work happens here
        }
        // Otherwise the CPU is free -- it could sleep with __WFI(),
        // or run an entirely unrelated task.
    }
}
