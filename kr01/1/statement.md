|                      |       |
|----------------------|-------|
| **Time limit:**      | `1 s` |
| **Real time limit:** | `5 s` |
| **Memory limit:**    | `64M` |


### Problem kr01-1: asm/ints/abcd-3

Определите (выделите память под) три глобальных 32-битных целых знаковых переменных `A`, `B`, `R`.
Напишите функцию `process`, которая вычисляет `R = A * 5 - B / 8`.

Умножение следует реализовать на основе сложений и сдвигов, инструкции умножения (mul) и деления
(div) запрещены. В сдаваемом файле должны быть определены только переменные и функция process.

Размещайте код в секции .text

Размещайте данные в секции .data

Не портите значения A и B

Если значение `A * 5 - B / 8` не представимо 32-битным целым знаковым числом, значение R должно
остаться неизменным

Деление должно производиться по стандартным математическим правилам - округление вниз

### Examples

#### Input

    
    
    1 64

#### Output

    
    
    -1

#### Input

    
    
    -100 -100

#### Output

    
    
    -293
