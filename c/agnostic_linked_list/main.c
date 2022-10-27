#include <stdio.h>
#include <stdlib.h>
#include "agnostic_queue.h"

struct DataSt {
    int key1;
    int key2;
};

void debug_print(struct Queue *q) {
    printf("\n===========================================\n");
    struct DataSt *data;

    if(q->front != NULL) {
        data = (struct DataSt *)q->front->data;
        printf("DQueue Front: %d-%d\n", data->key1, data->key2);
    } else {
        printf("DQueue Front: NULL\n");
    }

    if(q->rear != NULL) {
        data = (struct DataSt *)q->rear->data;
        printf("DQueue Rear: %d-%d\n", data->key1, data->key2);
    } else {
        printf("DQueue Rear: NULL\n");
    }

    printf("Queue size: %ld\n", q->size);
    printf("Is Empty? %d\n", isEmpty(q));

    printf("\n");

    for(struct QNode *n = q->front; n != NULL; n = n->next) {
        data = (struct DataSt *)n->data;
        printf("%d-%d -> ", data->key1, data->key2);
    }
    printf("NULL\n");

    printf("===========================================\n\n");
}

// Driver Program to test above functions
int main() {
    struct Queue* q = createQueue();
    int index = 0;
    struct DataSt data;
    size_t data_size = sizeof(data);

    debug_print(q);

    data.key1 = 10;
    data.key2 = 11;
    printf("append %d-%d\n", data.key1, data.key2);
    append(q, (char *)&data, data_size);

    debug_print(q);

    data.key1 = 20;
    data.key2 = 21;
    printf("append %d-%d\n", data.key1, data.key2);
    append(q, (char *)&data, data_size);

    debug_print(q);

    data.key1 = 30;
    data.key2 = 31;
    printf("append %d-%d\n", data.key1, data.key2);
    append(q, (char *)&data, data_size);

    debug_print(q);

    data.key1 = 5;
    data.key2 = 6;
    index = 0;
    printf("insert %d-%d at index %d\n", data.key1, data.key2, index);
    insertIndex(q, index, (char *)&data, data_size);

    debug_print(q);

    data.key1 = 200;
    data.key2 = 201;
    index = 50;
    printf("insert %d-%d at index %d\n", data.key1, data.key2, index);
    insertIndex(q, index, (char *)&data, data_size);

    debug_print(q);

    data.key1 = 40;
    data.key2 = 41;
    printf("append %d-%d\n", data.key1, data.key2);
    append(q, (char *)&data, data_size);

    debug_print(q);

    data.key1 = 50;
    data.key2 = 51;
    printf("append %d-%d\n", data.key1, data.key2);
    append(q, (char *)&data, data_size);

    debug_print(q);

    printf("Reverse");
    reverse(q);

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
