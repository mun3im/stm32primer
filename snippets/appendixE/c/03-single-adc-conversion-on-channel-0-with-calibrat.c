// STM32 Primer, Appendix E -- Single ADC conversion on channel 0 with calibration
// Source: appendix.tex, line 1469. Extracted as printed in the book; it may be a fragment, not a complete program.

void adc_init(void)
{
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_ADC1EN;

        RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_ADCPRE)
        | RCC_CFGR_ADCPRE_DIV6;

        GPIOA->CRL &= ~(0xFU << 0U);             // PA0 = analog in

        ADC1->SMPR2 |= (7U << 0U);               // channel 0: 239.5 cyc.
        ADC1->SQR3   = 0U;                       // first conv: channel 0

        ADC1->CR2 |= ADC_CR2_ADON;               // wake the ADC
        for (volatile int i = 0; i < 1000; i++) { }   // let it stabilize

        ADC1->CR2 |= ADC_CR2_CAL;                // calibrate once
        while (ADC1->CR2 & ADC_CR2_CAL) { }

        ADC1->CR2 |= ADC_CR2_EXTSEL | ADC_CR2_EXTTRIG;  // SW trigger
}

uint16_t adc_read(void)
{
        ADC1->CR2 |= ADC_CR2_SWSTART;
        while ((ADC1->SR & ADC_SR_EOC) == 0U) { }
        return (uint16_t)ADC1->DR;
}
