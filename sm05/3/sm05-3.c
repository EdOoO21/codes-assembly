// #include <cstdint>
#include <stdio.h>

#define LEN(a) (sizeof(a) / sizeof(a[0]))
#define LL long long

int mystrcmp(const char *str1, const char *str2) {
    int type = 0;
    while ((*str1 != '\0') && (*str2 != '\0')) {
        if ((unsigned)*str1 > (unsigned)*str2) {
            type = 1;
            break;
        } else if ((unsigned)*str1 < (unsigned)*str2) {
            type = -1;
            break;
        }
        ++str1;
        ++str2;
    }
    if ((type == 0) && (*str1 != '\0')) {
        type = 1;
    } else if ((type == 0) && (*str2 != '\0')) {
        type = -1;
    }
    return type;
}

int main(void) {
    char first[100], second[200];
    scanf("%s %s", first, second);
    printf("%d\n",mystrcmp(first, second));
    return 0;
}