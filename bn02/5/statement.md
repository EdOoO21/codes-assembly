|                      |           |
|----------------------|-----------|
| **Time limit:**      | `1500 ms` |
| **Real time limit:** | `5 s`     |
| **Memory limit:**    | `64M`     |


### Problem bn02-5: c/floats/intrinsics-gorilla

Напишите функцию `int gorilla(const int *a, int n, const int *b, int m)`.

Горилла принимает строго возрастающую последовательность целых чисел `a` длины `n` и строго
возрастающую последовательность целых чисел `b` длины `m`.

Горилла должна возвращать количество чисел, которые входят как `a`, так и в `b`.

Подсказка: используйте AVX инструкции

