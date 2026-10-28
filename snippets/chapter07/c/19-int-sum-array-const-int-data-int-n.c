// STM32 Primer, Chapter 7
// Source: chapter7.tex, line 1261. Extracted as printed in the book; it may be a fragment, not a complete program.

int sum_array(const int *data, int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += data[i];
    return total;
}
