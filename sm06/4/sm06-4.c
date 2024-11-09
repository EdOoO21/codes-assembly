// #include <cstddef>
#include <stdio.h>

typedef enum {
    FIRST = 0xe0,
    SECOND = 0xC0,
    THIRD = 0xD3,
    FOURTH = 0xBF,
    FIVTH = 0xD0,
    SIXTH = 0x80,
    SEVENTH = 0xf8,
    EIGHTH = 0xf0,
} Val;

int main() {
    size_t letts = 0, cyrc = 0;
    while (1) {
        int l = getchar();
        if (l == EOF) {
            break;
        }
        char start = (char)l;

        if ((start & FIRST) == SECOND) {
            int sec = getchar();
            if ((l <= THIRD) && (sec <= FOURTH) && (l >= FIVTH) &&
                (sec >= SIXTH)) {
                ++cyrc;
            }
        } else if ((start & EIGHTH) == FIRST) {
            l = getchar();
            l = getchar();
        } else if ((start & SEVENTH) == EIGHTH) {
            l = getchar();
            l = getchar();
            l = getchar();
        }

        ++letts;
    }

    printf("%zu %zu\n", letts, cyrc);
    return 0;
}
