// STM32 Primer, Appendix E -- Run the Blue Pill at 72\,MHz from the 8\,MHz crystal
// Source: appendix.tex, line 1212. Extracted as printed in the book; it may be a fragment, not a complete program.

void clock_72mhz(void)
{
        RCC->CR |= RCC_CR_HSEON;                       // start the crystal
        while ((RCC->CR & RCC_CR_HSERDY) == 0U) { }    // wait until stable

        FLASH->ACR |= FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY_2;  // wait states

        RCC->CFGR |= RCC_CFGR_PLLSRC        // PLL input = HSE
        |  RCC_CFGR_PLLMULL9      // 8 MHz x 9 = 72 MHz
        |  RCC_CFGR_PPRE1_DIV2    // APB1 = 36 MHz (its maximum)
        |  RCC_CFGR_ADCPRE_DIV6;  // ADC clock = 12 MHz (max 14)

        RCC->CR |= RCC_CR_PLLON;                       // start the PLL
        while ((RCC->CR & RCC_CR_PLLRDY) == 0U) { }

        RCC->CFGR |= RCC_CFGR_SW_PLL;                  // switch to the PLL
        while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) { }

        SystemCoreClock = 72000000U;                   // keep it honest
}
