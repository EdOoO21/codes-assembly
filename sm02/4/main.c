#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// Функция, которая вызывает вашу ассемблерную функцию
int invoke(int16_t *arr, int size, int pivot);

void print_array(int16_t *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generate_test(int size, int pivot) {
    int16_t arr[size];

    // Генерация случайных чисел для массива
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Числа от 0 до 99
    }

    // Гарантируем, что pivot находится в массиве
    int pivot_position = rand() % size; // Случайная позиция для pivot
    arr[pivot_position] = pivot;

    // Вывод информации о тесте
    printf("Test: size = %d, pivot = %d\n", size, pivot);
    printf("Original array: ");
    print_array(arr, size);

    // Вызов функции partition
    int mid = invoke(arr, size, pivot);

    // Вывод результата
    printf("Partitioned array: ");
    print_array(arr, size);
    printf("Returned mid: %d\n", mid);
    printf("----------------------------------\n");
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    // Вызовы generate_test с разными размерами массивов и значениями pivot
    generate_test(10, 5);
    generate_test(8, 20);
    generate_test(15, 7);
    generate_test(6, 13);
    generate_test(12, 50);

    // Добавленные 20 дополнительных тестов
    generate_test(10, 30);
    generate_test(8, 15);
    generate_test(20, 25);
    generate_test(18, 5);
    generate_test(25, 40);
    generate_test(30, 60);
    generate_test(5, 8);
    generate_test(16, 20);
    generate_test(14, 10);
    generate_test(22, 35);
    generate_test(19, 15);
    generate_test(9, 17);
    generate_test(11, 19);
    generate_test(7, 25);
    generate_test(13, 55);
    generate_test(24, 33);
    generate_test(21, 41);
    generate_test(26, 50);
    generate_test(17, 22);

    return 0;
}
