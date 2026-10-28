// STM32 Primer, Chapter 6 -- Summing an Array in C
// Source: chapter6.tex, line 688. Extracted as printed in the book; it may be a fragment, not a complete program.

int array[10];
int sum = 0;
int i;

for (i = 0; i < 10; i++) {
    sum += array[i];
}
