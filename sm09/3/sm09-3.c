#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

struct Node {
    int32_t key;
    int32_t left_idx;
    int32_t right_idx;
};

void go(int32_t index, int fd) {
    struct Node node;

    int64_t diff = index * sizeof(node);

    if (lseek(fd, diff, SEEK_SET) == -1) {
        exit(EXIT_FAILURE);
    };

    if (read(fd, &node, sizeof(node)) != sizeof(node)) {
        exit(EXIT_FAILURE);
    }

    if (node.right_idx != 0) {
        go(node.right_idx, fd);
    }

    printf("%d ", node.key);

    if (node.left_idx != 0) {
        go(node.left_idx, fd);
    }
}

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    go(0, fd);
    printf("\n");
    close(fd);
    return 0;
}

// int read_node_by_index(int32_t idx, struct Node *node) {
//     long offset = (long)idx * (long)sizeof(*node);
//     if (lseek(fd, offset, SEEK_SET) == -1L) {
//         perror("lseek");
//         return -1;
//     }
//     int r = read(fd, node, sizeof(*node));
//     if (r != (int)sizeof(*node)) {
//         perror("read");
//         return -1;
//     }
//     return 0;
// }

// void print_descending(int32_t idx) {
//     struct Node node;
//     if (read_node_by_index(idx, &node) < 0) {
//         exit(EXIT_FAILURE);
//     }
//     if (node.right_idx != 0) {
//         print_descending(node.right_idx);
//     }
//     if (first) {
//         printf("%d", node.key);
//         first = 0;
//     } else {
//         printf(" %d", node.key);
//     }
//     if (node.left_idx != 0) {
//         print_descending(node.left_idx);
//     }
// }

// void print_descending(int32_t idx) {
//     struct Node node;
//     if (node.right_idx != 0) {
//         print_descending(node.right_idx);
//     }
//     if (first) {
//         printf("%d", node.key);
//         first = 0;
//     } else {
//         printf(" %d", node.key);
//     }
//     if (node.left_idx != 0) {
//         print_descending(node.left_idx);
//     }
// }
