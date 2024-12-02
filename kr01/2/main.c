#include <stdio.h>
#include <stddef.h>

extern size_t count(char *buf);

int main() {

    char str[] = "0123acbde...9";
    size_t c = count(str);
    printf("%zu\n", c);
    return 0;
}