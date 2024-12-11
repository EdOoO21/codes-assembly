#include "read_file.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum Val {
    BUF_SIZE = 4096,
};

struct FileContent read_file(int fd) {

    char *buf = calloc(BUF_SIZE, 1);
    if (buf == NULL) {
        struct FileContent ans = {.size = -1, .data = NULL};
        return ans;
    }

    size_t total = 0, alloc_size = BUF_SIZE;
    int64_t readed = 0;
    char *new_buf = NULL;

    while ((readed = read(fd, (buf + total), BUF_SIZE)) > 0) {
        total += readed;
        if ((total + BUF_SIZE) > alloc_size) {
            alloc_size <<= 1;
            new_buf = realloc(buf, alloc_size);
            if (new_buf == NULL) {
                free(buf);
                struct FileContent ans = {.size = -1, .data = NULL};
                return ans;
            }
            buf = new_buf;
        }
    }
    if (readed == -1) {
        free(buf);
        struct FileContent ans = {.size = -1, .data = NULL};
        return ans;
    }

    new_buf = realloc(buf, total + 1);
    if (new_buf == NULL) {
        free(buf);
        struct FileContent ans = {.size = -1, .data = NULL};
        return ans;
    }
    buf = new_buf;
    buf[total] = 0;
    struct FileContent ans = {.size = total, .data = buf};
    return ans;
}
