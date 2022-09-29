#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main(void) {
    struct binaryTree *t = createBinaryTree();

    int value = 4;
    insert(t, value);

    value = 3;
    insert(t, value);

    value = 8;
    insert(t, value);

    value = 6;
    insert(t, value);

    value = 1;
    insert(t, value);

    value = 10;
    insert(t, value);

    value = 6;
    lookup(t, value);

    value = 10;
    lookup(t, value);

    value = 4;
    lookup(t, value);

    value = 3;
    lookup(t, value);

    value = 1;
    lookup(t, value);

    value = 0;
    lookup(t, value);

    free(t);

    return 0;
}
