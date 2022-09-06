#include <stdio.h>
#include <stdlib.h>
#include "int_queue.h"

// Driver Program to test above functions
int main() {
    struct Queue* q = createQueue();

    printf("Is Empty? %d\n", isEmpty(q));
    enQueue(q, 10);
    printf("Added one element\n");

    enQueue(q, 20);
    printf("Added one element\n");

    printf("Is Empty? %d\n", isEmpty(q));

    printQueue(q);
    deQueue(q);
    printf("Removed one element\n");

    deQueue(q);
    printf("Removed one element\n");

    printf("Is Empty? %d\n", isEmpty(q));

    enQueue(q, 30);
    printf("Added one element\n");

    enQueue(q, 40);
    printf("Added one element\n");

    enQueue(q, 50);
    printf("Added one element\n");

    printf("Is Empty? %d\n", isEmpty(q));

    printQueue(q);
    deQueue(q);
    printf("Removed one element\n");

    printf("Queue Front : %d\n", q->front->key);
    printf("Queue Rear : %d\n", q->rear->key);
    printf("Is Empty? %d\n", isEmpty(q));

    deQueue(q); // Removing last queue items to avoid memory leak
    printf("Removed one element\n");
    deQueue(q);
    printf("Removed one element\n");
    printf("Is Empty? %d\n", isEmpty(q));

    free(q); // Free queue to avoid memory leak
    return 0;
}
