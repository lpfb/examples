#include <stdio.h>
#include <stdlib.h>
#include "int_queue.h"

struct Queue *createQueue() {
    struct Queue *new_queue = (struct Queue*)malloc(sizeof(struct Queue));

    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->size = 0;

    return new_queue;
}

struct QNode *createNode(int key) {
    struct QNode *new_node = (struct QNode*)malloc(sizeof(struct QNode));

    new_node->key = key;
    new_node->next = NULL;

    return new_node;
}

void enQueue(struct Queue *queue, int key) {
    struct QNode *new_node = createNode(key);

    if(queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    }

    queue->rear->next = new_node; // update rear to next pointer
    queue->rear = new_node; // update rear node to the new one
    queue->size += 1;
}

void deQueue(struct Queue *queue) {

    if(queue->front == NULL)
        return;

    struct QNode *prev_front = queue->front;
    queue->front = prev_front->next;

    queue->size -= 1;

    if(queue->front == NULL)
        queue->rear = NULL;

    free(prev_front);
}

int isEmpty(struct Queue *queue) {
    if(queue->size <= 0)
        return 1;

    return 0;
}

void printQueue(struct Queue *queue) {
    if(queue->front == NULL)
        return;

    for(struct QNode *n = queue->front; n != NULL; n = n->next) {
        printf("%d -> ", n->key);
    }
    printf("NULL\n");
}
