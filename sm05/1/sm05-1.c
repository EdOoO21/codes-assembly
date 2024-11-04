#include <stdio.h>

int main(void) {
    unsigned a;
    unsigned b;
    if (scanf("%u %u", &a, &b) != 2) {
        printf("%u\n", 1);
        return 1;
    }
    unsigned ans = ((a / 2) + (b / 2)) + (((a % 2) + (b % 2)) / 2);

    if (printf("%u\n", ans) < 1) {
        printf("%u\n", 2);
        return 1;
    }
    return 0;
}