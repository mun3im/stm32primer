// STM32 Primer, Chapter 10 -- A Millisecond Time Base with SysTick
// Source: chapter10.tex, line 275. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f4xx.h"

volatile uint32_t msTicks = 0;       // written by ISR, read by main

void SysTick_Handler(void) {
msTicks++;                       // called once per millisecond
}

// Non-blocking elapsed-time check
uint32_t millis(void) {
return msTicks;
}

// Blocking delay, but now accurate
void delay_ms(uint32_t ms) {
uint32_t start = msTicks;
while ((msTicks - start) < ms) {
        // could __WFI() here to save power
}
}

int main(void) {
SysTick_Config(16000000 / 1000); // interrupt every 1 ms at 16 MHz

RCC->AHB1ENR |= (1U << 0);
GPIOA->MODER &= ~(3U << (5 * 2));
GPIOA->MODER |=  (1U << (5 * 2));

uint32_t last = 0;
while (1) {
        if ((millis() - last) >= 500) {   // non-blocking: no waiting
                last += 500;
                GPIOA->ODR ^= (1U << 5);
        }
        // other tasks run here, unimpeded
}

}
