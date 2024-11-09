#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

typedef enum {
    JUST_EIGHT = 8,
    JUST_SIXTEEN = 16,
} Val;

typedef struct Block {
    uint64_t size;
    struct Block *next;
} Block;

size_t align8(size_t size) {
    int delay = (JUST_EIGHT - (size % JUST_EIGHT)) % JUST_EIGHT;
    return size + delay;
}

extern Block *freelist;

void *alloc_mem(size_t size) {

    if (freelist) {
        Block *current = freelist, *prev = NULL;
        while (current) {
            if (current->size >= size) {
                if (prev == NULL) {
                    freelist = NULL;
                } else {
                    prev->next = current->next;
                }
                return ((char *)current) + JUST_EIGHT;
            }
            prev = current;
            current = current->next;
        }
    }

    size_t actual_size =
        align8(size) > JUST_EIGHT ? align8(size) + JUST_EIGHT : JUST_SIXTEEN;
    void *res = sbrk(actual_size);
    if (res != (void *)-1) {
        Block *block = (Block *)res;
        block->size = actual_size;
        block->next = NULL;
        return ((char *)block) + JUST_EIGHT;
    }
    return NULL;
}

void free_mem(void *ptr) {
    if (ptr != NULL) {
        Block *block = (Block *)((char *)ptr - JUST_EIGHT);
        if (freelist == NULL) {
            freelist = block;
            block->next = NULL;
        } else {
            block->next = freelist;
            freelist = block;
        }
    }
}

void test_reuse_freed_block() {
    size_t size = 32;  // Размер для тестирования
    void *block1 = alloc_mem(size);  // Выделение блока
    assert(block1 != NULL);          // Проверка, что выделение прошло успешно

    free_mem(block1);                // Освобождение блока

    // Попробуем снова запросить блок такого же размера
    void *block2 = alloc_mem(size);
    assert(block2 == block1);        // Проверка, что повторная аллокация вернула тот же адрес

    printf("test_reuse_freed_block passed\n");
}

int main() {
    test_reuse_freed_block();
    return 0;
}