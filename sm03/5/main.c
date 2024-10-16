#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Прототип функции сортировки по абсолютным значениям
extern void sort_by_abs(short *arr, size_t n);

// Функция для вывода массива
void print_array(short *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Функция для генерации случайного массива
void generate_random_array(short *arr, size_t n, short min, short max) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = (rand() % (max - min + 1)) + min;
    }
}

int main() {
    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Размер массива
    size_t n = 10; // например, массив из 10 элементов

    // Диапазон значений для генерации
    short min = -100;
    short max = 100;

    // Выделение памяти под массив
    short *arr = malloc(n * sizeof(short));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Генерация случайного массива
    generate_random_array(arr, n, min, max);

    // Вывод исходного массива
    printf("Original array: ");
    print_array(arr, n);

    // Вызов функции сортировки по абсолютным значениям
    sort_by_abs(arr, n);

    // Вывод отсортированного массива
    printf("Sorted by absolute values: ");
    print_array(arr, n);

    // Освобождение памяти
    free(arr);

    return 0;
}
