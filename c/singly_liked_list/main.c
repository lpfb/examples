#include <stdio.h>
#include <stdlib.h>
#include "int_queue.h"

// Driver Program to test above functions
int main() {
    struct Queue* q = createQueue();
    int value = 0;
    int index = 0;

    printf("Is Empty? %d\n", isEmpty(q));

    value = 10;
    printf("Added %d\n", value);
    append(q, value);
    printQueue(q);

    value = 20;
    printf("Added %d\n", value);
    append(q, value);
    printQueue(q);


    printf("Is Empty? %d\n", isEmpty(q));

    /* printf("Removed one element\n"); */
    /* pop(q); */
    /* printQueue(q); */
    /*  */
    /* printf("Removed one element\n"); */
    /* pop(q); */
    /* printQueue(q); */
    /*  */
    /* printf("Is Empty? %d\n", isEmpty(q)); */

    value = 30;
    printf("Added %d\n", value);
    append(q, value);
    printQueue(q);

    value = 5;
    index = 0;
    printf("Added %d at index %d\n", value, index);
    insertIndex(q, index, value);
    printQueue(q);

    value = 200;
    index = 50;
    printf("Added %d at index %d\n", value, index);
    insertIndex(q, index, value);
    printQueue(q);

    value = 40;
    printf("Added %d\n", value);
    append(q, value);
    printQueue(q);

    value = 50;
    printf("Added %d\n", value);
    append(q, value);
    printQueue(q);

    printf("Is Empty? %d\n", isEmpty(q));

    pop(q);
    printf("Removed one element\n");
    printQueue(q);

    printf("Queue Front : %d\n", q->front->key);
    printf("Queue Rear : %d\n", q->rear->key);
    printf("Is Empty? %d\n", isEmpty(q));

    index = 5;
    removeIndex(q, index);
    printf("Removed at index %d\n", index);
    printQueue(q);

    pop(q); // Removing last queue items to avoid memory leak
    printf("Removed one element\n");
    printQueue(q);
    pop(q);
    printf("Removed one element\n");
    printQueue(q);
    printf("Is Empty? %d\n", isEmpty(q));
    pop(q);
    printf("Removed one element\n");
    printQueue(q);

    index = -1;
    removeIndex(q, index);
    printf("Removed at index %d\n", index);
    printQueue(q);

    index = 0;
    removeIndex(q, index);
    printf("Removed at index %d\n", index);
    printQueue(q);

    /* printf("Queue Front : %d\n", q->front->key); */
    /* printf("Queue Rear : %d\n", q->rear->key); */

    /* index = 1; */
    /* removeIndex(q, index); */
    /* printf("Removed at index %d\n", index); */
    /* printQueue(q); */
    /*  */
    /* index = -1; */
    /* removeIndex(q, index); */
    /* printf("Removed at index %d\n", index); */
    /* printQueue(q); */

    free(q); // Free queue to avoid memory leak
    return 0;
}
