// STM32 Primer, Chapter 10 -- Blinking an LED from a Timer Interrupt
// Source: chapter10.tex, line 214. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

void TIM2_IRQHandler(void) {
if (TIM2->SR & (1U << 0)) {      // update interrupt flag set?
        TIM2->SR = ~(1U << 0);       // clear UIF, or the ISR never exits
        GPIOA->ODR ^= (1U << 5);     // toggle the LED
}
}

int main(void) {
// GPIO: PA5 as output
RCC->AHB1ENR |= (1U << 0);
GPIOA->MODER &= ~(3U << (5 * 2));
GPIOA->MODER |=  (1U << (5 * 2));

// Timer: enable TIM2 clock (APB1 bit 0)
RCC->APB1ENR |= (1U << 0);

// 500 ms period from 16 MHz:
//   (PSC+1)(ARR+1) = 8,000,000
TIM2->PSC = 1599;                // 16 MHz / 1600 = 10 kHz
TIM2->ARR = 4999;                // 10 kHz / 5000 = 2 Hz -> 500 ms

TIM2->DIER |= (1U << 0);         // enable update interrupt
TIM2->CR1  |= (1U << 0);         // CEN: start counting

NVIC_EnableIRQ(TIM2_IRQn);
__enable_irq();

while (1) {
        // Completely free. Could sleep here with __WFI().
}

}
