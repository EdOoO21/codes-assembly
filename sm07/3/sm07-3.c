#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void encode(const void *data, void *encoded, size_t n) {
    uint8_t *dats = (uint8_t *)data;
    uint16_t *encs = (uint16_t *)encoded;

    for (int x = 0; x < n; ++x) {
        size_t n1 = 8;
        uint8_t dat = dats[x];
        uint16_t enc = 0;

        for (int i = 0; i < 8; ++i) {
            enc |= ((dat >> i) & 1) << i;
        }

        for (int i = 8; i < (2 * n1 - 1); ++i) {
            enc |=
                ((((dat >> (i - n1)) & 1) ^ ((dat >> (i + 1 - n1)) & 1)) << i);
        }

        enc |= ((((dat >> 0) & 1) ^ ((dat >> (n1 - 1)) & 1)) << (2 * n1 - 1));
        encs[x] = enc;
    }
}

void decode(const void *encoded, void *data, size_t n) {
    uint8_t *dats = (uint8_t *)data;
    uint16_t *encs = (uint16_t *)encoded;

    for (int x = 0; x < n; ++x) {
        size_t n1 = 8;
        uint16_t enc = encs[x];
        uint8_t dat = 0;

        int error_pos = -1, first = 0;
        int parity_error_count = 0;

        for (int i = 0; i < n1; ++i) {
            uint8_t bit1 = (enc >> i) & 1;
            uint8_t bit2 = (enc >> ((i + 1) % n1)) & 1;
            uint8_t parity_bit = (enc >> (i + n1)) & 1;

            if ((bit1 ^ bit2) != parity_bit) {
                parity_error_count++;
                if (parity_error_count == 2) {
                    error_pos = i;
                    break;
                } else {
                    first = i;
                }
            }
        }

        if ((error_pos != -1) && (parity_error_count == 2)) {
            if ((error_pos == 7) && (first == 0)) {
                error_pos = 0;
            }
            enc ^= (1 << error_pos);
        }

        for (size_t i = 0; i < n1; ++i) {
            dat |= ((enc >> i) & 1) << i;
        }

        dats[x] = dat;
    }
}

void print_binary(uint16_t num, size_t bits) {
    for (size_t i = 0; i < bits; ++i) {
        printf("%d", (num >> (bits - 1 - i)) & 1);
    }
    printf("\n");
}

// Функция для теста с двоичными числами
void test_encode_decode() {
    // Тест 1: Простой случай с одним байтом
    uint8_t data1[] = {0b11001010};
    size_t n1 = sizeof(data1) / sizeof(data1[0]);
    uint16_t encoded1[n1];
    uint8_t decoded1[n1];

    printf("Test 1: Original data: ");
    print_binary(data1[0], 8);

    encode(data1, encoded1, n1);
    printf("Encoded data: ");
    for (size_t i = 0; i < n1; ++i) {
        print_binary(encoded1[i], 16);
    }

    decode(encoded1, decoded1, n1);
    printf("Decoded data: ");
    for (size_t i = 0; i < n1; ++i) {
        print_binary(decoded1[i], 8);
    }

    if (data1[0] == decoded1[0]) {
        printf("Test 1 passed!\n");
    } else {
        printf("Test 1 failed!\n");
    }

    // Тест 2: Два байта данных
    uint8_t data2[] = {0b11001010, 0b10111001};
    size_t n2 = sizeof(data2) / sizeof(data2[0]);
    uint16_t encoded2[n2];
    uint8_t decoded2[n2];

    printf("\nTest 2: Original data: ");
    for (size_t i = 0; i < n2; ++i) {
        print_binary(data2[i], 8);
    }

    encode(data2, encoded2, n2);
    printf("Encoded data: ");
    for (size_t i = 0; i < n2; ++i) {
        print_binary(encoded2[i], 16);
    }

    decode(encoded2, decoded2, n2);
    printf("Decoded data: ");
    for (size_t i = 0; i < n2; ++i) {
        print_binary(decoded2[i], 8);
    }

    int test2_passed = 1;
    for (size_t i = 0; i < n2; ++i) {
        if (data2[i] != decoded2[i]) {
            test2_passed = 0;
            break;
        }
    }
    if (test2_passed) {
        printf("Test 2 passed!\n");
    } else {
        printf("Test 2 failed!\n");
    }

    // Тест 3: Введение ошибки в один бит
    uint8_t data3[] = {0b11001010};
    size_t n3 = sizeof(data3) / sizeof(data3[0]);
    uint16_t encoded3[n3];
    uint8_t decoded3[n3];

    printf("\nTest 3: Original data: ");
    print_binary(data3[0], 8);

    encode(data3, encoded3, n3);
    printf("Encoded data: ");
    for (size_t i = 0; i < n3; ++i) {
        print_binary(encoded3[i], 16);
    }

    encoded3[0] ^= (1 << 5);  // Инвертируем 5-й бит

    printf("Encoded data with error: ");
    for (size_t i = 0; i < n3; ++i) {
        print_binary(encoded3[i], 16);
    }

    decode(encoded3, decoded3, n3);
    printf("Decoded data: ");
    for (size_t i = 0; i < n3; ++i) {
        print_binary(decoded3[i], 8);
    }

    if (data3[0] == decoded3[0]) {
        printf("Test 3 passed!\n");
    } else {
        printf("Test 3 failed!\n");
    }

    // Тест 4: Массив байтов с множественными ошибками
    uint8_t data4[] = {0b11001010, 0b10101100};
    size_t n4 = sizeof(data4) / sizeof(data4[0]);
    uint16_t encoded4[n4];
    uint8_t decoded4[n4];

    printf("\nTest 4: Original data: ");
    for (size_t i = 0; i < n4; ++i) {
        print_binary(data4[i], 8);
    }

    encode(data4, encoded4, n4);
    printf("Encoded data: ");
    for (size_t i = 0; i < n4; ++i) {
        print_binary(encoded4[i], 16);
    }

    encoded4[0] ^= (1 << 7);  // Ошибка в первом элементе
    encoded4[1] ^= (1 << 9);  // Ошибка во втором элементе

    printf("Encoded data with errors: ");
    for (size_t i = 0; i < n4; ++i) {
        print_binary(encoded4[i], 16);
    }

    decode(encoded4, decoded4, n4);
    printf("Decoded data: ");
    for (size_t i = 0; i < n4; ++i) {
        print_binary(decoded4[i], 8);
    }

    int test4_passed = 1;
    for (size_t i = 0; i < n4; ++i) {
        if (data4[i] != decoded4[i]) {
            test4_passed = 0;
            break;
        }
    }
    if (test4_passed) {
        printf("Test 4 passed!\n");
    } else {
        printf("Test 4 failed!\n");
    }
}

int main() {
    test_encode_decode();
    return 0;
}