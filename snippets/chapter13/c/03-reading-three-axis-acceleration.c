// STM32 Primer, Chapter 13 -- Reading Three-Axis Acceleration
// Source: chapter13.tex, line 369. Extracted as printed in the book; it may be a fragment, not a complete program.

#define REG_DEVID        0x00
#define REG_POWER_CTL    0x2D
#define REG_DATA_FORMAT  0x31
#define REG_DATAX0       0x32

void accel_init(void) {
    spi_init();
    sensor_write_reg(REG_DATA_FORMAT, 0x00);  // +/-2g, right justify
    sensor_write_reg(REG_POWER_CTL,   0x08);  // exit standby, start
}

// Combine two 8-bit registers into one signed 16-bit reading.
int16_t accel_read_axis(uint8_t reg_low) {
    uint8_t lo = sensor_read_reg(reg_low);
    uint8_t hi = sensor_read_reg(reg_low + 1);
    return (int16_t)((uint16_t)hi << 8 | lo);   // little-endian pair
}

// Convert a raw count to g, using +/- 2g scale factor of 3.9 mg/LSB.
float accel_to_g(int16_t raw) {
    return (float)raw * 0.0039f;
}
