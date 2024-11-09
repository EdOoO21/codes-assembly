#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

// Объявление внешних функций
extern size_t align8(size_t size);
extern void *alloc_mem(size_t size);
extern void free_mem(void *ptr);

typedef struct Block {
    uint64_t size;
    struct Block *next;
} Block;

// Глобальная переменная freelist для тестов
Block *freelist = NULL;  // Определение и инициализация freelist

// Тест для функции align8
void test_align8() {
    assert(align8(1) == 8);       // Минимум должно быть 8
    assert(align8(5) == 8);       // Округление вверх до 8
    assert(align8(16) == 16);     // Округление вверх до 16
    assert(align8(17) == 24);     // Округление вверх до ближайшего кратного 8
    printf("test_align8 passed\n");
}

// Тест для функции alloc_mem
void test_alloc_mem() {
    printf("test_alloc_mem started\n");
    Block *block1 = (Block *)alloc_mem(10);
    assert(block1 != NULL);

    Block *block2 = (Block *)alloc_mem(20);
    assert(block2 != NULL);

    printf("test_alloc_mem passed\n");
}

// Тест для функции free_mem
void test_free_mem() {
    Block *block1 = (Block *)alloc_mem(10);
    free_mem(block1);
    assert(freelist == block1);  // После освобождения блок должен попасть в freelist

    Block *block2 = (Block *)alloc_mem(20);
    free_mem(block2);
    assert(freelist == block2);  // Теперь block2 должен быть в freelist

    printf("test_free_mem passed\n");
}

int main() {
    test_align8();      // Проверка функции align8
    test_alloc_mem();   // Проверка функции alloc_mem
    test_free_mem();    // Проверка функции free_mem
    return 0;
}
