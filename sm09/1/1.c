#include "read_file.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum Const { STANDARD_BUFFER_SIZE = 4096 };

struct FileContent read_file(int fd) {
    struct FileContent res = {.size = -1, .data = NULL};
    size_t res_size = 0, buf_size = STANDARD_BUFFER_SIZE;
    int64_t len = 0;
    char *buffer = calloc(buf_size, 1), *temp = NULL;
    if (buffer == NULL) {
        return res;
    }
    while ((len = read(fd, (buffer + res_size), STANDARD_BUFFER_SIZE)) > 0) {
        res_size += len;
        if (res_size + STANDARD_BUFFER_SIZE > buf_size) {
            buf_size *= 2;
            temp = realloc(buffer, buf_size);
            if (temp == NULL) {
                free(buffer);
                return res;
            }
            buffer = temp;
        }
    }
    if (len == -1) {
        free(buffer);
        return res;
    }
    temp = realloc(buffer, res_size + 1);
    if (temp == NULL) {
        free(buffer);
        return res;
    }
    buffer = temp;
    buffer[res_size] = 0;
    res.size = res_size;
    res.data = buffer;
    return res;
}
