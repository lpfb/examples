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

void append(struct Queue *queue, int key) {
    struct QNode *new_node = createNode(key);

    if(queue->size == 0) {
        queue->front = new_node;
    } else {
        queue->rear->next = new_node; // update rear to next pointer
    }

    queue->rear = new_node; // update rear node to the new one
    queue->size++;
}

void pop(struct Queue *queue) {

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

void insertIndex(struct Queue *queue, int index, int key) {
    if(queue->size == 0 || index >= queue->size) {
        append(queue, key);
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

void removeIndex(struct Queue *queue, int index) {
    if(queue->size == 0) {
        return;
    }

    if(index <= 0) {
        pop(queue);
        return;
    }

    if(index >= queue->size) { // Remove last item
        index = queue->size-2;
    } else {
        index -= 1;
    }

    struct QNode *node_to_delete;
    struct QNode *leader = traverseList(queue, index);

    if(leader == queue->front) {
        node_to_delete = queue->front;
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        node_to_delete = leader->next;
        leader->next = node_to_delete->next;

        if(node_to_delete == queue->rear)
            queue->rear = leader;
    }

    free(node_to_delete);

    queue->size--;
}

void reverse(struct Queue *queue) {
    // Reference: https://www.youtube.com/watch?v=XgABnoJLtG4
    if(queue->size <= 1) {
        return;
    }

    struct QNode *prev = NULL;
    struct QNode *next = NULL;

    queue->rear = queue->front;

    while(queue->front != NULL) {
        next = queue->front->next;
        queue->front->next = prev;
        prev = queue->front;
        queue->front = next;
    }

    queue->front = prev;
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
    printf("NULL\n");
}
