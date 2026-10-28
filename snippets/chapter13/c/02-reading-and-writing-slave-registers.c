// STM32 Primer, Chapter 13 -- Reading and Writing Slave Registers
// Source: chapter13.tex, line 344. Extracted as printed in the book; it may be a fragment, not a complete program.

// Typical convention: bit 7 set = read, clear = write
#define SPI_READ   0x80

uint8_t sensor_read_reg(uint8_t reg) {
    CS_LOW();
    spi_transfer(reg | SPI_READ);      // send addr, receive garbage
    uint8_t value = spi_transfer(0x00); // send dummy, receive data
    CS_HIGH();
    return value;
}

void sensor_write_reg(uint8_t reg, uint8_t value) {
    CS_LOW();
    spi_transfer(reg & ~SPI_READ);     // addr w/ read bit clear
    spi_transfer(value);
    CS_HIGH();
}
