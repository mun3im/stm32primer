// STM32 Primer, Chapter 10 -- PWM LED Dimming on PA5 using TIM2 Channel 1
// Source: chapter10.tex, line 513. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

int main(void) {
RCC->AHB1ENR |= (1U << 0);          // GPIOA clock
RCC->APB1ENR |= (1U << 0);          // TIM2 clock

// PA5 to alternate function mode (10)
GPIOA->MODER &= ~(3U << (5 * 2));
GPIOA->MODER |=  (2U << (5 * 2));

// Select AF1 (TIM2) for pin 5. Pins 0-7 use AFR[0], 4 bits each.
GPIOA->AFR[0] &= ~(0xFU << (5 * 4));
GPIOA->AFR[0] |=  (1U << (5 * 4));

// 1 kHz PWM from 16 MHz:
//   timer clock 1 MHz, then 1000 counts per period
TIM2->PSC = 15;                     // 16 MHz / 16 = 1 MHz
TIM2->ARR = 999;                    // 1 MHz / 1000 = 1 kHz

// Channel 1: PWM mode 1 (output high while CNT < CCR1)
TIM2->CCMR1 &= ~(7U << 4);
TIM2->CCMR1 |=  (6U << 4);          // OC1M = 110 = PWM mode 1
TIM2->CCMR1 |=  (1U << 3);          // OC1PE: preload enable
TIM2->CCER  |=  (1U << 0);          // CC1E: enable channel 1 output

TIM2->CCR1 = 500;                   // 500/1000 = 50% duty
TIM2->CR1  |= (1U << 0);             // start the timer

while (1) {
        // Ramp the brightness up and down by varying CCR1 only.
        for (uint32_t d = 0; d < 1000; d += 10) {
                TIM2->CCR1 = d;
                for (volatile uint32_t w = 0; w < 20000; w++);
        }
        for (uint32_t d = 1000; d > 0; d -= 10) {
                TIM2->CCR1 = d;
                for (volatile uint32_t w = 0; w < 20000; w++);
        }
}

}
