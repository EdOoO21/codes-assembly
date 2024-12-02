|                      |          |
|----------------------|----------|
| **Time limit:**      | `250 ms` |
| **Real time limit:** | `5 s`    |
| **Memory limit:**    | `64M`    |


### Problem sm07-5: c/algorithms/matrix-multiply

Дан код перемножающий вектор на матрицу некоторое количество раз.

Изменив РОВНО 1 строчку ускорьте код (чтобы результат остался корректным) и сдайте полученное
решение в ejudge.

Изменение не должно добавлять новых фигурных скобок и символов `;`, а также не должно содержать
return, goto pragma и подобных.

    
    
    #include <stdio.h>
    #include <stdlib.h>
    
    #define N 1024
    
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

P.S. Ускорение зависит от вашего процессора. В системе установлен какой-то Intel Xeon. Как видно из
данных ниже потенциально все данные влезают в кеш

    
    
    L1d cache:                       64 KiB (2 instances)
    L1i cache:                       64 KiB (2 instances)
    L2 cache:                        4 MiB (1 instance)
    L3 cache:                        16 MiB (1 instance)

Может быть полезно знать [что такое 4-way associative
cache](http://www.vlsiip.com/cache/cache_0003.html) и [какие необычности он
привносит](https://en.algorithmica.org/hpc/cpu-cache/associativity/)

Код компилируется с флагом -O2

