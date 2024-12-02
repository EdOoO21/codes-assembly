#include <stdio.h>
#include <math.h>

float okay(float x, float y, float z);

int main() {
    float result1 = okay(16.0f, 3.0f, 10.0f);
    float result2 = okay(0.0f, 3.0f, 10.0f);

    printf("Result1: %.10f\n", result1); // Ожидается: 7.754887502
    printf("Result2: %.10f\n", result2); // Ожидается: 0.4201670368
    return 0;
}