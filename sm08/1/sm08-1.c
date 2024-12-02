#include <stdio.h>


// печатаем число в бинарном виде
// первый аргмент - само число, второй аргумент
// - сколько бит нужно печатать
void print_bin(unsigned n, unsigned size) {
    unsigned i;
    for (i = 1 << (size - 1); i > 0; i = i >> 1) {
        (n & i) ? printf("1") : printf("0");
    }
    printf("\n");
}

typedef enum FPClass {
    FFP_ZERO,          // нули
    FFP_DENORMALIZED,  // числа в денормализованной форме
    FFP_NORMALIZED,  // числа в нормализованной форме
    FFP_INF,         // бесконечности
    FFP_NAN          // NaN-ы
} FPClass;

#include <string.h>

enum Val {
    EXP_MASK = 0b11111111,
    ZERO_EXP_MASK = 0b00000000,
    MANTISSA_MASK = 0b11111111111111111111111,
    SIGN_BITS = 1,
    MANT_BITS = 23,
    EXP_BITS = 8,
};

unsigned get_exp(float num) {
    unsigned exp;
    memcpy(&exp, &num, sizeof(num));

    return exp << SIGN_BITS >> (SIGN_BITS + MANT_BITS);
}

unsigned get_mant(float num) {

    unsigned mant;
    memcpy(&mant, &num, sizeof(num));

    int to_remove = SIGN_BITS + EXP_BITS;

    return mant << (to_remove) >> to_remove;
}

unsigned get_sign(float num) {
    unsigned sign;
    memcpy(&sign, &num, sizeof(num));

    return sign >> (MANT_BITS + EXP_BITS);
}

FPClass fpclassf(float value, int *psign) {
    unsigned sign = get_sign(value);
    unsigned mant = get_mant(value);
    unsigned exp = get_exp(value);
    if ((exp & EXP_MASK) == EXP_MASK) {
        if ((mant & MANTISSA_MASK) == 0) {
            *psign = sign;
            return FFP_INF;
        } else {
            *psign = 0;
            return FFP_NAN;
        }
    } else if ((exp & EXP_MASK) == ZERO_EXP_MASK) {
        if ((mant & MANTISSA_MASK) == 0) {
            *psign = sign;
            return FFP_ZERO;
        } else {
            *psign = sign;
            return FFP_DENORMALIZED;
        }
    }
    *psign = sign;
    return FFP_NORMALIZED;
}

int main() {
    float f = -114.3;
    int val = 0;
    int *psign = &val;
    fpclassf(f, psign);
    printf("psign = %d \n", *psign);
    printf("------------------------------------\n");
    f = 0;
    fpclassf(f, psign);
    printf("psign = %d \n", *psign);

    printf("------------------------------------\n");
    f = 0.000000000000000000000000000000000000000000001401298;
    fpclassf(f, psign);
    printf("psign = %d \n", *psign);

    printf("------------------------------------\n");
}