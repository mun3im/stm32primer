// STM32 Primer, Appendix E -- Blink PC13 with SysTick
// Source: appendix.tex, line 1435. Extracted as printed in the book; it may be a fragment, not a complete program.

#include "stm32f1xx.h"

static volatile uint32_t ticks;
void SysTick_Handler(void) { ticks++; }

static void delay_ms(uint32_t ms)
{
        uint32_t start = ticks;
        while ((ticks - start) < ms) { }
}

int main(void)
{
        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;      // GPIOC clock
        (void)RCC->APB2ENR;

        // PC13 is pin 13, so it lives in CRH at nibble (13 - 8) = 5
        GPIOC->CRH = (GPIOC->CRH & ~(0xFU << 20U)) | (0x2U << 20U);

        SysTick_Config(SystemCoreClock / 1000U); // 1 ms tick

        while (1) {
                GPIOC->BSRR = (1U << (13U + 16U));   // drive low:  LED on
                delay_ms(500U);
                GPIOC->BSRR = (1U << 13U);           // drive high: LED off
                delay_ms(500U);
        }
}
