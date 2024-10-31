#include <stdio.h>
extern "C"
short megacall(int x, int y, int z, char a, char b, char c, long long delta, int omega, short eps);

short megacall(int x, int y, int z, char a, char b, char c, long long delta, int omega, short eps) {
    printf("started\n");
    printf("x y z input");
    printf("\n%d", x);
    printf("\n");
    printf("%d", y);
    printf("\n");
    printf("%d", z);
    printf("\n");
    printf("a b c chars\n");
    putchar(a);
    printf("\n");
    putchar(b);
    printf("\n");
    putchar(c);
    printf("\n");
    printf("delta omega eps other\n");
    printf("%lld", delta);
    printf("\n");
    printf("%d", omega);
    printf("\n");
    printf("%hd\n", eps);
    return -2;
}
