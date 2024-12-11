#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

enum Val {
    BYTE = 8,
};

int main(int argc, char *argv[]) {
    int fd_file1 = open(argv[1], O_RDONLY);
    int fd_file2 =
        open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    int index = 0, bit;
    int64_t val;
    int32_t mod = atoi(argv[3]);
    int32_t res = 0;
    unsigned char bits;

    while (read(fd_file1, &bits, 1) == 1) {
        for (int i = 0; i < BYTE; ++i) {
            bit = ((bits >> i) & 1);
            val = (index + (i + 1)) % mod;
            val = (val * val) % mod;
            res = (((res % mod) + (val % mod)) % mod);
            if (bit == 1) {
                ssize_t len = write(fd_file2, &res, sizeof(int32_t));
                if (len == -1) {
                    exit(EXIT_FAILURE);
                }
            }
        }
        index += BYTE;
    }
    return 0;
}
