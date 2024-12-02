#include <stdio.h>
#include <stdlib.h>

#define LEN(a) (sizeof(a) / sizeof(a[0]))

typedef struct NodeT {
    int key;
    size_t size;
    struct NodeT *left;
    struct NodeT *right;
} NodeT;

NodeT *node_new(int key) {
    NodeT *vertex = (NodeT *)calloc(1, sizeof(*vertex));
    vertex->key = key;
    vertex->size = 1;
    vertex->left = NULL;
    vertex->right = NULL;
    return vertex;
}

NodeT *node_merge(NodeT *v, NodeT *u) {
    if (v == NULL) {
        return u;
    }
    if (u == NULL) {
        return v;
    }
    NodeT *a;
    if (v->key > u->key) {
        a = v->left;
        v->left = v->right;
        v->right = a;
        v->left = node_merge(v->left, u);
        v->size = 1 + (v->right != NULL ? v->right->size : 0) +
                  (v->left != NULL ? v->left->size : 0);
        return v;
    } else {
        a = u->left;
        u->left = u->right;
        u->right = a;
        u->left = node_merge(u->left, v);
        u->size = 1 + (u->right != NULL ? u->right->size : 0) +
                  (u->left != NULL ? u->left->size : 0);
        return u;
    }
}

size_t node_size(NodeT *v) {
    if (v == NULL) {
        return 0;
    }
    return v->size;
}

NodeT *node_pop(NodeT *v, int *key) {
    NodeT *right = v->right, *left = v->left;
    NodeT *res = node_merge(left, right);
    if (key != NULL) {
        *key = v->key;
    }
    free(v);
    return res;
}
