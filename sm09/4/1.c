#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>


enum Val {
    BYTE = 8,
};

int main(int argc, char *argv[]) {
    int fd_file1 = open(argv[1], O_WRONLY | O_TRUNC);
    unsigned char byte[2] = {0x93, 0x93};

    write(fd_file1, &byte, sizeof(unsigned char) * 2);
    return 0;
}