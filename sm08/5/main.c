#include <stdio.h>
#include <math.h>

// Прототип функции product, реализованной на ассемблере
void product(int n, const float *x, const float *y, float *result);

// Утилита для сравнения результатов с учётом плавающей точки
int compare_float(float a, float b, float epsilon) {
    return fabs(a - b) < epsilon;
}

void run_test(int test_number, int n, const float *x, const float *y, float expected) {
    float result = 0.0f;
    product(n, x, y, &result);

    if (compare_float(result, expected, 1e-6)) {
        printf("Test #%d passed: result = %f (expected %f)\n", test_number, result, expected);
    } else {
        printf("Test #%d failed: result = %f (expected %f)\n", test_number, result, expected);
    }
}
int main() {
    // Тест 6: Все элементы равны нулю
    {
        float x[] = {0.0f, 0.0f, 0.0f};
        float y[] = {0.0f, 0.0f, 0.0f};
        float expected = 0.0f;
        run_test(6, 3, x, y, expected);
    }

    // Тест 7: Все элементы отрицательные
    {
        float x[] = {-1.0f, -2.0f, -3.0f, -4.0f};
        float y[] = {-5.0f, -6.0f, -7.0f, -8.0f};
        float expected =
            (-1.0f * -5.0f) - (-2.0f * -6.0f) + (-3.0f * -7.0f) - (-4.0f * -8.0f);
        run_test(7, 4, x, y, expected);
    }

    // Тест 8: Один большой элемент
    {
        float x[] = {1e6f};
        float y[] = {1e-6f};
        float expected = 1.0f; // 1e6 * 1e-6 = 1.0
        run_test(8, 1, x, y, expected);
    }

    // Тест 9: Чередование нулей и ненулевых элементов
    {
        float x[] = {0.0f, 2.0f, 0.0f, 4.0f};
        float y[] = {3.0f, 0.0f, 5.0f, 0.0f};
        float expected =
            (0.0f * 3.0f) - (2.0f * 0.0f) + (0.0f * 5.0f) - (4.0f * 0.0f);
        run_test(9, 4, x, y, expected);
    }

    // Тест 10: Малые числа, близкие к нулю
    {
        float x[] = {1e-7f, -1e-7f, 1e-8f};
        float y[] = {1e-6f, -1e-6f, 1e-6f};
        float expected =
            (1e-7f * 1e-6f) - (-1e-7f * -1e-6f) + (1e-8f * 1e-6f);
        run_test(10, 3, x, y, expected);
    }

    // Тест 11: Длинный массив с одинаковыми элементами
    {
        int n = 10;
        float x[10], y[10];
        for (int i = 0; i < n; i++) {
            x[i] = 2.0f;
            y[i] = -3.0f;
        }
        float expected = 0.0f;
        for (int i = 0; i < n; i++) {
            expected += (i % 2 == 0 ? 1 : -1) * x[i] * y[i];
        }
        run_test(11, n, x, y, expected);
    }

    // Тест 12: Чередующиеся единицы
    {
        float x[] = {1.0f, 1.0f, 1.0f, 1.0f};
        float y[] = {1.0f, 1.0f, 1.0f, 1.0f};
        float expected =
            (1.0f * 1.0f) - (1.0f * 1.0f) + (1.0f * 1.0f) - (1.0f * 1.0f);
        run_test(12, 4, x, y, expected);
    }

    // Тест 13: Пограничное значение n = 1
    {
        float x[] = {3.5f};
        float y[] = {2.5f};
        float expected = 3.5f * 2.5f; // Чётный индекс, знак "+"
        run_test(13, 1, x, y, expected);
    }

    // Тест 14: Пограничное значение n = 2
    {
        float x[] = {1.0f, -2.0f};
        float y[] = {2.0f, 3.0f};
        float expected =
            (1.0f * 2.0f) - (-2.0f * 3.0f);
        run_test(14, 2, x, y, expected);
    }

    // Тест 15: Случай, где результат равен 0
    {
        float x[] = {1.0f, 1.0f, 1.0f, 1.0f};
        float y[] = {1.0f, -1.0f, 1.0f, -1.0f};
        float expected =
            (1.0f * 1.0f) - (1.0f * -1.0f) + (1.0f * 1.0f) - (1.0f * -1.0f);
        run_test(15, 4, x, y, expected);
    }

    return 0;
}
