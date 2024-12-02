#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN(a) (sizeof(a) / sizeof(a[0]))

enum Variables {
    ONE = 1,
    DEGONE = -1,
    ZERO = 0,
    ZEROSTR = '0',
    TWO = 2,
    FOUR = 4,
    PLUS = '+',
    MINUS = '-',
};

int main(int argc, char *argv[]) {
    for (int i = ONE; i < argc; ++i) {
        char *pointer = argv[i];
        char *end = NULL;
        long a = strtol(argv[i], &end, 10);
        if (*end != '\0') {
            printf("%d\n", -1);
        } else if (a == ZERO) {
            if ((*pointer == PLUS) || (*pointer == MINUS)) {
                ++pointer;
                ++argv[i];
            }
            while (*pointer == ZEROSTR) {
                ++pointer;
            }
            if (pointer != argv[i]) {
                printf("%d\n", ONE);
            } else {
                printf("%d\n", DEGONE);
            }
        } else {
            int8_t x = (int8_t)a;
            int16_t x1 = (int16_t)a;
            int32_t x2 = (int32_t)a;
            if (x == a) {
                printf("%d\n", ONE);
            } else if (x1 == a) {
                printf("%d\n", TWO);
            } else if (x2 == a) {
                printf("%d\n", FOUR);
            } else {
                printf("%d\n", DEGONE);
            }
        }
    }
}
