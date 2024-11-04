// #include <cstdint>
#include <stdio.h>

#define LEN(a) (sizeof(a) / sizeof(a[0]))
#define LL long long

void normalize_path(char *buf) {
    char *now = buf;
    char *can_be_replaced = buf;
    int prev_is_slash = 0;
    while (*now != '\0') {
        if (prev_is_slash == 1) {
            if (*now != '/') {
                prev_is_slash = 0;
                *can_be_replaced = *now;
                ++now;
                ++can_be_replaced;
            } else {
                ++now;
            }
        } else {
            if (*now == '/') {
                prev_is_slash = 1;
            }
            *can_be_replaced = *now;
            ++now;
            ++can_be_replaced;
        }
    }
    *can_be_replaced = '\0';
}

int main(void) {
    char first[100];
    scanf("%s", first);
    normalize_path(first);
    printf("%s\n", first);
    return 0;
}