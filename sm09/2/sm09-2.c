#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

struct FileWriteState {
    int fd;  // "файловый дескриптор", для вывода на стандартный поток вывода -
             // 1
    unsigned char *buf;  // указатель на буфер
    ssize_t bufsize;     // размер буфера
    ssize_t now;         // индекс сейчас
    // здесь потребуется добавить поля для реализации буферизованной записи
};

enum Val {
    SIZE = 4096,
};

unsigned char buf[SIZE];
struct FileWriteState buffer = {.fd = 1, .buf = buf, .bufsize = SIZE, .now = 0};

struct FileWriteState *stout = &buffer;

void flush(struct FileWriteState *out) {
    asm("syscall"
        :
        : "a"(SYS_write), "D"(out->fd), "S"(out->buf), "d"(out->now));
    out->now = 0;
}

void writechar(int c, struct FileWriteState *out) {
    unsigned char lett = (unsigned char)c;

    out->buf[out->now] = lett;
    ++out->now;

    if (out->now == SIZE) {
        flush(out);
    }
}
