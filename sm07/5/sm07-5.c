#include <stdio.h>
#include <stdlib.h>

#define N 1025

void mul(int *A, int *B, int *res) {
    for (int i = 0; i != N; ++i) {
        int s = 0;
        for (int j = 0; j != N; ++j) {
            s += A[j] * B[j * N + i];
        }
        res[i] = s;
    }
}

int main() {
    int * A = calloc(N * N, sizeof(*A));
    int * B = calloc(N, sizeof(*A));
    int * C = calloc(N, sizeof(*A));

    srand(42);

    for (int i = 0; i != 1024; ++i) {
        B[i] = rand();
        for (int j = 0; j != 1024; ++j) {
            A[i * N + j] = rand();
        }
    }

    for (int i = 0; i != 64; ++i) {
        mul(B, A, C);
        mul(C, A, B);
    }

    for (int i = 0; i != 1024; ++i) {
        printf("%d ", B[i] % 4);
    }
    printf("\n");

    free(A);
    free(B);
    free(C);
}