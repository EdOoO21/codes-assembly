#include <stdio.h>

#define LEN(a) (sizeof(a) / sizeof(a[0]))
#define LL long long

int main(void) {
    int a, b, n;
    if (scanf("%d %d %d", &a, &b, &n) != 3) {
        return 1;
    }

    printf("%*s", n, " ");
    for (int i = a; i < b; ++i) {
        printf(" %*d", n, i);
    }
    printf("\n");

    for (LL i = a; i < b; ++i) {
        printf("%*lld", n, i);
        for (LL j = a; j < b; ++j) {
            printf(" %*lld", n, i * j);
        }
        printf("\n");
    }
}
