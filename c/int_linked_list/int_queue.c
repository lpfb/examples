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

void pushQueue(struct Queue *queue, int key) {
    struct QNode *new_node = createNode(key);

    if(queue->size == 0) {
        queue->front = new_node;
    } else {
        queue->rear->next = new_node; // update rear to next pointer
    }

    queue->rear = new_node; // update rear node to the new one
    queue->size += 1;
}

void popQueue(struct Queue *queue) {

    if(queue->size == 0)
        return;

    struct QNode *prev_front = queue->front;
    queue->front = prev_front->next;

    queue->size -= 1;

    if(queue->front == NULL)
        queue->rear = NULL;

    free(prev_front);
}

void insertQueue(struct Queue *queue, int index, int key) {
    if(queue->size == 0) {
        pushQueue(queue, key);
        return;
    }

    if(index > queue->size-1) {
        return;
    }

    struct QNode *new_node = createNode(key);

    struct QNode *prev_node = queue->front;

    int i = 0;
    for(struct QNode *n = queue->front; n != NULL; n = n->next) {
        if(i == index) {
            new_node->next = n;
            queue->size += 1;

            if(n == queue->front)
                queue->front = new_node;
            else
                prev_node->next = new_node;

            break;
        }
        prev_node = n;
        i += 1;
    }
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
