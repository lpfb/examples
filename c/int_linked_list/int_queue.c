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
    queue->size++;
}

void popQueue(struct Queue *queue) {

    if(queue->size == 0)
        return;

    struct QNode *prev_front = queue->front;
    queue->front = prev_front->next;

    queue->size--;

    if(queue->front == NULL)
        queue->rear = NULL;

    free(prev_front);
}

struct QNode *traverseList(struct Queue *queue, int index) {
    int i = 0;

    struct QNode *index_node = queue->front;

    if(index <= 0)
        return index_node;

    while(i != index) {
        index_node = index_node->next;
        i++;
    }

    return index_node;
}

void insertQueue(struct Queue *queue, int index, int key) {
    if(queue->size == 0 || index >= queue->size) {
        pushQueue(queue, key);
        return;
    }

    struct QNode *new_node = createNode(key);

    if(index <= 0) {
        new_node->next = queue->front;
        queue->front = new_node;

    } else {
        struct QNode *leader = traverseList(queue, index-1);

        new_node->next = leader->next;
        leader->next = new_node;
    }

    queue->size++;
}

void deleteQueue(struct Queue *queue, int index) {
    if(queue->size == 0) {
        return;
    }

    if(index <= 0) {
        popQueue(queue);
        return;
    }

    if(index >= queue->size) {
        index = queue->size-2;
    } else {
        index -= 1;
    }

    struct QNode *node_to_delete;

    if(queue->size == 1) {
        node_to_delete = queue->front;
        queue->front = NULL;

    } else {
        struct QNode *leader = traverseList(queue, index);
        node_to_delete = leader->next;

        leader->next = node_to_delete->next;

    }

    free(node_to_delete);

    if(queue->front == NULL)
        queue->rear = NULL;

    queue->size--;
}

int isEmpty(struct Queue *queue) {
    if(queue->size <= 0)
        return 1;

    return 0;
}

void printQueue(struct Queue *queue) {
    for(struct QNode *n = queue->front; n != NULL; n = n->next) {
        printf("%d -> ", n->key);
    }
    printf("NULL (QSize: %ld)\n", queue->size);
}
