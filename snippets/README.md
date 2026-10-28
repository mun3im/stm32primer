# Code snippets from *STM32 Primer*

Every `lstlisting` in the book with more than five non-blank lines, copied exactly as printed.
`c/` holds C (`.c`), `arm/` holds ARM assembly (`.s`). Files are numbered in the order they appear in the chapter.
Many are fragments that rely on surrounding text (for example, a function without `main`); each file's header says so and gives the source line.

Regenerate after editing the book with `python3 tools/extract_snippets.py`; it updates files in place. Listings come from `chapterN.tex` and `appendix.tex` in the current release's source folder.

| Folder | File | Caption | Source |
|---|---|---|---|
| chapter04/arm | `01-mov-r0-5-x-5.s` | — | chapter4.tex:57 |
| chapter04/c | `02-typedef-struct.c` | — | chapter4.tex:148 |
| chapter04/c | `03-pure-cmsis-register-level-blinky.c` | Pure CMSIS Register-Level Blinky | chapter4.tex:550 |
| chapter04/c | `04-a-bare-metal-program-configure-once-then-loop-fo.c` | A bare-metal program: configure once, then loop forever | chapter4.tex:601 |
| chapter05/arm | `01-a-complete-arm-assembly-program.s` | A Complete ARM Assembly Program | chapter5.tex:41 |
| chapter06/arm | `01-ldr-r0-a.s` | — | chapter6.tex:41 |
| chapter06/c | `02-summing-an-array-in-c.c` | Summing an Array in C | chapter6.tex:688 |
| chapter06/arm | `03-summing-an-array-in-assembly.s` | Summing an Array in Assembly | chapter6.tex:698 |
| chapter07/arm | `01-implementing-a-plain-if-structure.s` | Implementing a Plain If Structure | chapter7.tex:235 |
| chapter07/arm | `02-implementing-an-if-else-structure.s` | Implementing an If-Else Structure | chapter7.tex:337 |
| chapter07/arm | `03-testing-one-bit-of-a-peripheral-register.s` | Testing One Bit of a Peripheral Register | chapter7.tex:488 |
| chapter07/c | `04-sum-0.c` | — | chapter7.tex:513 |
| chapter07/arm | `05-mov-r0-0.s` | — | chapter7.tex:522 |
| chapter07/arm | `06-polling-a-status-bit.s` | Polling a Status Bit | chapter7.tex:542 |
| chapter07/c | `07-sum-0.c` | — | chapter7.tex:557 |
| chapter07/arm | `08-mov-r0-0.s` | — | chapter7.tex:566 |
| chapter07/arm | `09-ldr-r1-0x5555.s` | — | chapter7.tex:591 |
| chapter07/arm | `10-counting-up-loop.s` | Counting-Up Loop | chapter7.tex:633 |
| chapter07/arm | `11-foo.s` | — | chapter7.tex:843 |
| chapter07/arm | `12-popcount.s` | — | chapter7.tex:866 |
| chapter07/arm | `13-popcount.s` | — | chapter7.tex:880 |
| chapter07/arm | `14-main.s` | — | chapter7.tex:904 |
| chapter07/arm | `15-push-r4.s` | — | chapter7.tex:1044 |
| chapter07/arm | `16-nested-subroutine-call-with-lr-preserved.s` | Nested subroutine call with LR preserved | chapter7.tex:1119 |
| chapter07/arm | `17-foo-push-r4-r5-save-regs-this-function-will-use.s` | — | chapter7.tex:1190 |
| chapter07/arm | `18-caller-a-d-already-in-r0-r3-e-goes-on-the-stack.s` | — | chapter7.tex:1236 |
| chapter07/c | `19-int-sum-array-const-int-data-int-n.c` | — | chapter7.tex:1261 |
| chapter07/arm | `20-sum-array.s` | — | chapter7.tex:1272 |
| chapter08/c | `01-experiment-1-blinking-an-led-via-odr.c` | Experiment 1 --- Blinking an LED via ODR | chapter8.tex:229 |
| chapter08/c | `02-experiment-2-blinking-via-atomic-bsrr-writes.c` | Experiment 2 --- Blinking via Atomic BSRR Writes | chapter8.tex:256 |
| chapter08/c | `03-experiment-3-button-controls-led.c` | Experiment 3 --- Button Controls LED | chapter8.tex:283 |
| chapter08/c | `04-experiment-4-debounced-press-toggles-the-led.c` | Experiment 4 --- Debounced Press Toggles the LED | chapter8.tex:346 |
| chapter08/c | `05-experiment-5-binary-counter-on-four-leds.c` | Experiment 5 --- Binary Counter on Four LEDs | chapter8.tex:386 |
| chapter08/c | `06-experiment-6-measuring-reaction-time.c` | Experiment 6 --- Measuring Reaction Time | chapter8.tex:424 |
| chapter08/c | `07-experiment-7-driving-a-common-cathode-display-fr.c` | Experiment 7 --- Driving a Common-Cathode Display from Port C | chapter8.tex:492 |
| chapter09/c | `01-while-1.c` | — | chapter9.tex:24 |
| chapter09/c | `02-external-interrupt-pc13-sets-a-flag.c` | External Interrupt: PC13 Sets a Flag | chapter9.tex:475 |
| chapter09/c | `03-shared-interrupt-handler-for-pc13-and-pb10.c` | Shared Interrupt Handler for PC13 and PB10 | chapter9.tex:676 |
| chapter10/c | `01-blinking-an-led-from-a-timer-interrupt.c` | Blinking an LED from a Timer Interrupt | chapter10.tex:214 |
| chapter10/c | `02-a-millisecond-time-base-with-systick.c` | A Millisecond Time Base with SysTick | chapter10.tex:275 |
| chapter10/c | `03-void-exti15-10-irqhandler-void.c` | — | chapter10.tex:328 |
| chapter10/c | `04-pwm-led-dimming-on-pa5-using-tim2-channel-1.c` | PWM LED Dimming on PA5 using TIM2 Channel 1 | chapter10.tex:513 |
| chapter11/c | `01-polling-based-adc-reading.c` | Polling-Based ADC Reading | chapter11.tex:237 |
| chapter11/c | `02-interrupt-driven-adc.c` | Interrupt-Driven ADC | chapter11.tex:301 |
| chapter12/c | `01-configuring-usart2-on-pa2-pa3.c` | Configuring USART2 on PA2/PA3 | chapter12.tex:262 |
| chapter12/c | `02-sending-a-fixed-string-over-uart.c` | Sending a Fixed String Over UART | chapter12.tex:305 |
| chapter12/c | `03-displaying-every-character-received.c` | Displaying Every Character Received | chapter12.tex:353 |
| chapter12/c | `04-bare-metal-uart-echo-server.c` | Bare-Metal UART Echo Server | chapter12.tex:406 |
| chapter12/c | `05-printing-numbers-over-uart.c` | Printing Numbers Over UART | chapter12.tex:443 |
| chapter12/c | `06-uart-print-moder.c` | — | chapter12.tex:474 |
| chapter12/c | `07-receiving-characters-by-interrupt.c` | Receiving Characters by Interrupt | chapter12.tex:493 |
| chapter12/c | `08-configuring-a-second-usart-usart1-on-pb6-pb7.c` | Configuring a Second USART: USART1 on PB6/PB7 | chapter12.tex:560 |
| chapter13/c | `01-spi-master-initialization-and-transfer.c` | SPI Master Initialization and Transfer | chapter13.tex:295 |
| chapter13/c | `02-reading-and-writing-slave-registers.c` | Reading and Writing Slave Registers | chapter13.tex:344 |
| chapter13/c | `03-reading-three-axis-acceleration.c` | Reading Three-Axis Acceleration | chapter13.tex:369 |
| chapter13/c | `04-i2c-master-initialization.c` | I2C Master Initialization | chapter13.tex:668 |
| chapter13/c | `05-reading-one-register-over-i2c.c` | Reading One Register Over I2C | chapter13.tex:710 |
| chapter14/c | `01-while-1.c` | — | chapter14.tex:54 |
| chapter14/c | `02-void-exti15-10-irqhandler-void.c` | — | chapter14.tex:67 |
| chapter14/c | `03-integrated-sensor-monitor.c` | Integrated Sensor Monitor | chapter14.tex:199 |
| appendixC/arm | `01-unsigned-divide-by-10-and.s` | Unsigned divide by 10: $q = x / 10$ and $r = x \bmod 10$ | appendix.tex:636 |
| appendixC/arm | `02-signed-divide-by-10.s` | Signed divide by 10 ($q = x / 10$, $R0 = x$) | appendix.tex:675 |
| appendixC/c | `03-binary-to-packed-bcd-in-c.c` | Binary to packed BCD in C | appendix.tex:688 |
| appendixC/arm | `04-binary-to-packed-bcd-in-assembly-r0-in-4-bcd-dig.s` | Binary to packed BCD in assembly (R0 in, 4 BCD digits out in R0) | appendix.tex:701 |
| appendixE/c | `01-run-the-blue-pill-at-72-mhz-from-the-8-mhz-cryst.c` | Run the Blue Pill at 72\,MHz from the 8\,MHz crystal | appendix.tex:1212 |
| appendixE/c | `02-blink-pc13-with-systick.c` | Blink PC13 with SysTick | appendix.tex:1435 |
| appendixE/c | `03-single-adc-conversion-on-channel-0-with-calibrat.c` | Single ADC conversion on channel 0 with calibration | appendix.tex:1469 |
| appendixE/c | `04-usart1-transmit-at-9600-baud.c` | USART1 transmit at 9600 baud | appendix.tex:1502 |
