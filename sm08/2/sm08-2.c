#include <stdio.h>

enum Val {
    MAX_MANTISSA = 16777216,
};

unsigned checker(unsigned val) {
    if (val <= MAX_MANTISSA) {
        return 1;
    } else {
        while (val % 2 == 0) {
            val = val >> 1;
        }
        if (val <= MAX_MANTISSA) {
            return 1;
        }
    }
    return 0;
}

int main() {
    unsigned val;
    while (scanf("%u", &val) != EOF) {
        printf("%u\n", checker(val));
    }
    return 0;
}
