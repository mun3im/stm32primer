// STM32 Primer, Chapter 13 -- Reading One Register Over I2C
// Source: chapter13.tex, line 710. Extracted as printed in the book; it may be a fragment, not a complete program.

// addr is the 7-bit address ALREADY shifted left by one.
uint8_t i2c_read_reg(uint8_t addr, uint8_t reg) {
    while (I2C1->SR2 & (1U << 1)) { }        // wait for bus to be free

    // --- Phase 1: START, then address for WRITE ---
    I2C1->CR1 |= (1U << 8);                  // START
    while (!(I2C1->SR1 & (1U << 0))) { }     // SB: start condition sent
    I2C1->DR = addr & ~1U;                   // address + write bit
    while (!(I2C1->SR1 & (1U << 1))) { }     // ADDR: address acked
    (void)I2C1->SR2;                         // SR1 then SR2 clears ADDR

    // --- Phase 2: send the register number ---
    while (!(I2C1->SR1 & (1U << 7))) { }     // TXE: data register empty
    I2C1->DR = reg;
    while (!(I2C1->SR1 & (1U << 2))) { }     // BTF: byte transfer done

    // --- Phase 3: repeated START, then address for READ ---
    I2C1->CR1 |= (1U << 8);                  // repeated START
    while (!(I2C1->SR1 & (1U << 0))) { }     // SB
    I2C1->DR = addr | 1U;                    // address + read bit
    while (!(I2C1->SR1 & (1U << 1))) { }     // ADDR
    I2C1->CR1 &= ~(1U << 10);                // ACK = 0: NACK this byte
    (void)I2C1->SR2;                         // clear ADDR

    // --- Phase 4: receive one byte, then STOP ---
    I2C1->CR1 |= (1U << 9);                  // STOP
    while (!(I2C1->SR1 & (1U << 6))) { }     // RXNE: data received
    return (uint8_t)I2C1->DR;
}
