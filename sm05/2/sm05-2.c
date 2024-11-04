// #include <cstdint>
#include <stdint.h>
#include <stdio.h>

#define LEN(a) (sizeof(a) / sizeof(a[0]))
#define LL long long
#define SIZE 93

int main(void) {

    uint64_t arr[SIZE] = {1, 1};

    for (int i = 2; i < SIZE; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    LL a;
    while (scanf("%llx", &a) == 1) {
        for (int i = 1; i < SIZE; ++i) {
            if (arr[i] > a) {
                printf("%x ", i - 1);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}