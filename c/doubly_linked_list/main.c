#include <stdio.h>
#include <stdlib.h>
#include "int_queue.h"

void debug_print(struct DQueue *q) {
    printf("\n===========================================\n");
    if(q->front != NULL)
        printf("DQueue Front : %d\n", q->front->key);
    else
        printf("DQueue Front : NULL\n");

    if(q->rear != NULL)
        printf("DQueue Rear : %d\n", q->rear->key);
    else
        printf("DQueue Rear : NULL\n");
    printf("Queue size: %ld\n", q->size);
    printf("Is Empty? %d\n", isEmpty(q));

    printf("\n");
    printDQueue(q,0);
    printDQueue(q,1);
    printf("===========================================\n\n");
}

int main() {
    struct DQueue* q = createDQueue();
    int value = 0;
    int index = 0;

    debug_print(q);

    value = 10;
    printf("Append %d\n", value);
    append(q, value);

    debug_print(q);

    value = 20;
    printf("Append %d\n", value);
    append(q, value);

    debug_print(q);

    value = 30;
    printf("Append %d\n", value);
    append(q, value);

    debug_print(q);

    value = 5;
    index = 0;
    printf("Insert %d at index %d\n", value, index);
    insertIndex(q, index, value);

    debug_print(q);

    value = 200;
    index = 50;
    printf("Insert %d at index %d\n", value, index);
    insertIndex(q, index, value);

    debug_print(q);

    value = 40;
    printf("Append %d\n", value);
    append(q, value);

    debug_print(q);

    value = 50;
    printf("Append %d\n", value);
    append(q, value);

    debug_print(q);

    pop(q);
    printf("pop\n");

    debug_print(q);

    index = 5;
    removeIndex(q, index);
    printf("Remove at index %d\n", index);

    debug_print(q);

    pop(q);
    printf("pop\n");

    debug_print(q);

    pop(q);
    printf("pop\n");

    debug_print(q);

    pop(q);
    printf("pop\n");

    debug_print(q);

    index = -1;
    removeIndex(q, index);
    printf("Remove at index %d\n", index);

    debug_print(q);

    index = 0;
    removeIndex(q, index);
    printf("Remove at index %d\n", index);

    debug_print(q);

    free(q); // Free queue to avoid memory leak
    return 0;
}
