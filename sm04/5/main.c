#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Объявление функции НОД из ассемблера
extern long gcd(long n, long m);

// Функция для вычисления НОД на C
long gcd_c(long a, long b) {
    while (b != 0) {
        long temp = b;
        b = a % b;
        a = temp;
    }
    return a < 0 ? -a : a; // Возвращаем положительное значение
}

int main() {
    srand(time(NULL)); // Инициализируем генератор случайных чисел
    int num_tests = 100000; // Количество тестов

    for (int i = 0; i < num_tests; i++) {
        long n = rand() % 5000 - 2500; // Генерируем случайное число от -500 до 499
        long m = rand() % 5000 - 2500;
        printf("Test %d: gcd(%ld, %ld)\n", i + 1, n, m);
        // Вычисляем НОД с помощью ассемблера и C
        long result_asm = gcd(n, m);
        long result_c = gcd_c(n, m);

        // Вывод результатов
        printf("Test %d: gcd(%ld, %ld)\n", i + 1, n, m);
        printf("Assembly result: %ld\n", result_asm);
        printf("C result: %ld\n\n", result_c);

        // Проверка на совпадение результатов
        if (result_asm != result_c) {
            printf("Mismatch found!\n");
            return 1; // Завершаем с ошибкой, если результаты не совпадают
        }
    }

    printf("All tests passed successfully.\n");
    return 0;
}
