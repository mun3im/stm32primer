# Code snippets from *STM32 Primer*

Every `lstlisting` in the book with more than five non-blank lines, copied exactly as printed.
`c/` holds C (`.c`), `arm/` holds ARM assembly (`.s`). Files are numbered in the order they appear in the chapter.
Many are fragments that rely on surrounding text (for example, a function without `main`); each file's header says so and gives the source line.

Listings come from `chapterN.tex` and `appendix.tex` in the current release's source folder.

| Folder | File | Caption |
|---|---|---|
| chapter04/arm | `01-mov-r0-5-x-5.s` | — |
| chapter04/c | `02-typedef-struct.c` | — |
| chapter04/c | `03-pure-cmsis-register-level-blinky.c` | Pure CMSIS Register-Level Blinky |
| chapter04/c | `04-a-bare-metal-program-configure-once-then-loop-fo.c` | A bare-metal program: configure once, then loop forever |
| chapter05/arm | `01-a-complete-arm-assembly-program.s` | A Complete ARM Assembly Program |
| chapter06/arm | `01-ldr-r0-a.s` | — |
| chapter06/c | `02-summing-an-array-in-c.c` | Summing an Array in C |
| chapter06/arm | `03-summing-an-array-in-assembly.s` | Summing an Array in Assembly |
| chapter07/arm | `01-implementing-a-plain-if-structure.s` | Implementing a Plain If Structure |
| chapter07/arm | `02-implementing-an-if-else-structure.s` | Implementing an If-Else Structure |
| chapter07/arm | `03-testing-one-bit-of-a-peripheral-register.s` | Testing One Bit of a Peripheral Register |
| chapter07/c | `04-sum-0.c` | — |
| chapter07/arm | `05-mov-r0-0.s` | — |
| chapter07/arm | `06-polling-a-status-bit.s` | Polling a Status Bit |
| chapter07/c | `07-sum-0.c` | — |
| chapter07/arm | `08-mov-r0-0.s` | — |
| chapter07/arm | `09-ldr-r1-0x5555.s` | — |
| chapter07/arm | `10-counting-up-loop.s` | Counting-Up Loop |
| chapter07/arm | `11-foo.s` | — |
| chapter07/arm | `12-popcount.s` | — |
| chapter07/arm | `13-popcount.s` | — |
| chapter07/arm | `14-main.s` | — |
| chapter07/arm | `15-push-r4.s` | — |
| chapter07/arm | `16-nested-subroutine-call-with-lr-preserved.s` | Nested subroutine call with LR preserved |
| chapter07/arm | `17-foo-push-r4-r5-save-regs-this-function-will-use.s` | — |
| chapter07/arm | `18-caller-a-d-already-in-r0-r3-e-goes-on-the-stack.s` | — |
| chapter07/c | `19-int-sum-array-const-int-data-int-n.c` | — |
| chapter07/arm | `20-sum-array.s` | — |
| chapter08/c | `01-experiment-1-blinking-an-led-via-odr.c` | Experiment 1 --- Blinking an LED via ODR |
| chapter08/c | `02-experiment-2-blinking-via-atomic-bsrr-writes.c` | Experiment 2 --- Blinking via Atomic BSRR Writes |
| chapter08/c | `03-experiment-3-button-controls-led.c` | Experiment 3 --- Button Controls LED |
| chapter08/c | `04-experiment-4-debounced-press-toggles-the-led.c` | Experiment 4 --- Debounced Press Toggles the LED |
| chapter08/c | `05-experiment-5-binary-counter-on-four-leds.c` | Experiment 5 --- Binary Counter on Four LEDs |
| chapter08/c | `06-experiment-6-measuring-reaction-time.c` | Experiment 6 --- Measuring Reaction Time |
| chapter08/c | `07-experiment-7-driving-a-common-cathode-display-fr.c` | Experiment 7 --- Driving a Common-Cathode Display from Port C |
| chapter09/c | `01-while-1.c` | — |
| chapter09/c | `02-external-interrupt-pc13-sets-a-flag.c` | External Interrupt: PC13 Sets a Flag |
| chapter09/c | `03-shared-interrupt-handler-for-pc13-and-pb10.c` | Shared Interrupt Handler for PC13 and PB10 |
| chapter10/c | `01-blinking-an-led-from-a-timer-interrupt.c` | Blinking an LED from a Timer Interrupt |
| chapter10/c | `02-a-millisecond-time-base-with-systick.c` | A Millisecond Time Base with SysTick |
| chapter10/c | `03-void-exti15-10-irqhandler-void.c` | — |
| chapter10/c | `04-pwm-led-dimming-on-pa5-using-tim2-channel-1.c` | PWM LED Dimming on PA5 using TIM2 Channel 1 |
| chapter11/c | `01-polling-based-adc-reading.c` | Polling-Based ADC Reading |
| chapter11/c | `02-interrupt-driven-adc.c` | Interrupt-Driven ADC |
| chapter12/c | `01-configuring-usart2-on-pa2-pa3.c` | Configuring USART2 on PA2/PA3 |
| chapter12/c | `02-sending-a-fixed-string-over-uart.c` | Sending a Fixed String Over UART |
| chapter12/c | `03-displaying-every-character-received.c` | Displaying Every Character Received |
| chapter12/c | `04-bare-metal-uart-echo-server.c` | Bare-Metal UART Echo Server |
| chapter12/c | `05-printing-numbers-over-uart.c` | Printing Numbers Over UART |
| chapter12/c | `06-uart-print-moder.c` | — |
| chapter12/c | `07-receiving-characters-by-interrupt.c` | Receiving Characters by Interrupt |
| chapter12/c | `08-configuring-a-second-usart-usart1-on-pb6-pb7.c` | Configuring a Second USART: USART1 on PB6/PB7 |
| chapter13/c | `01-spi-master-initialization-and-transfer.c` | SPI Master Initialization and Transfer |
| chapter13/c | `02-reading-and-writing-slave-registers.c` | Reading and Writing Slave Registers |
| chapter13/c | `03-reading-three-axis-acceleration.c` | Reading Three-Axis Acceleration |
| chapter13/c | `04-i2c-master-initialization.c` | I2C Master Initialization |
| chapter13/c | `05-reading-one-register-over-i2c.c` | Reading One Register Over I2C |
| chapter14/c | `01-while-1.c` | — |
| chapter14/c | `02-void-exti15-10-irqhandler-void.c` | — |
| chapter14/c | `03-integrated-sensor-monitor.c` | Integrated Sensor Monitor |
| appendixC/arm | `01-unsigned-divide-by-10-and.s` | Unsigned divide by 10: $q = x / 10$ and $r = x \bmod 10$ |
| appendixC/arm | `02-signed-divide-by-10.s` | Signed divide by 10 ($q = x / 10$, $R0 = x$) |
| appendixC/c | `03-binary-to-packed-bcd-in-c.c` | Binary to packed BCD in C |
| appendixC/arm | `04-binary-to-packed-bcd-in-assembly-r0-in-4-bcd-dig.s` | Binary to packed BCD in assembly (R0 in, 4 BCD digits out in R0) |
| appendixE/c | `01-run-the-blue-pill-at-72-mhz-from-the-8-mhz-cryst.c` | Run the Blue Pill at 72\,MHz from the 8\,MHz crystal |
| appendixE/c | `02-blink-pc13-with-systick.c` | Blink PC13 with SysTick |
| appendixE/c | `03-single-adc-conversion-on-channel-0-with-calibrat.c` | Single ADC conversion on channel 0 with calibration |
| appendixE/c | `04-usart1-transmit-at-9600-baud.c` | USART1 transmit at 9600 baud |
