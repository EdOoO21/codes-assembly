#include <stdint.h>
#include <stdio.h>

enum {
    SIXTEEN = 16,
    KEY = 21846,
};

int main() {
    uint16_t n;
    if (scanf("%hu", &n) == 1) {
        n = (n * KEY) >> SIXTEEN;
        printf("%hu\n", n);
        return 0;
    }
    return 1;
}
