#include <stdio.h>
#include <stdlib.h>
#include "int_queue.h"

struct DQueue *createDQueue() {
    struct DQueue *new_queue = (struct DQueue*)malloc(sizeof(struct DQueue));

    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->size = 0;

    return new_queue;
}

struct DQNode *createNode(int key) {
    struct DQNode *new_node = (struct DQNode*)malloc(sizeof(struct DQNode));

    new_node->key = key;
    new_node->next = NULL;
    new_node->previous = NULL;

    return new_node;
}

void append(struct DQueue *queue, int key) {
    struct DQNode *new_node = createNode(key);

    if(queue->size == 0) {
        queue->front = new_node;
    } else {
        queue->rear->next = new_node; // update rear to next pointer
        new_node->previous = queue->rear; // add previous node
    }

    queue->rear = new_node; // update rear node to the new one
    queue->size++;
}

void pop(struct DQueue *queue) {

    if(queue->size == 0)
        return;

    struct DQNode *prev_front = queue->front;
    queue->front = prev_front->next;

    queue->size--;

    if(queue->front == NULL)
        queue->rear = NULL;
    else
        queue->front->previous = NULL; // In pop previous always will be NULL

    free(prev_front);
}

struct DQNode *traverseList(struct DQueue *queue, int index) {
    int i = 0;

    struct DQNode *index_node = queue->front;

    if(index <= 0)
        return index_node;

    while(i != index) {
        index_node = index_node->next;
        i++;
    }

    return index_node;
}

void insertIndex(struct DQueue *queue, int index, int key) {
    if(queue->size == 0 || index >= queue->size) {
        append(queue, key);
        return;
    }

    struct DQNode *new_node = createNode(key);

    if(index <= 0) {
        queue->front->previous = new_node;

        new_node->next = queue->front;
        queue->front = new_node;

    } else {
        struct DQNode *leader = traverseList(queue, index-1);

        new_node->next = leader->next;
        leader->next->previous = new_node;
        new_node->previous = leader;
        leader->next = new_node;
    }

    queue->size++;
}

void removeIndex(struct DQueue *queue, int index) {
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

    struct DQNode *node_to_delete;
    struct DQNode *leader = traverseList(queue, index);

    if(leader == queue->front) {
        node_to_delete = queue->front;
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        node_to_delete = leader->next;
        leader->next = node_to_delete->next;

        if(node_to_delete != queue->rear)
            node_to_delete->next->previous = leader;
        else
            queue->rear = leader;
    }

    free(node_to_delete);

    queue->size--;
}

int isEmpty(struct DQueue *queue) {
    if(queue->size <= 0)
        return 1;

    return 0;
}

void printDQueue(struct DQueue *queue, int reverse) {
    if(reverse) {
        printf("NULL ");
        for(struct DQNode *n = queue->rear; n != NULL; n = n->previous) {
            printf("<- %d ", n->key);
        }
        printf("<- NULL\n");
    } else {
        printf("NULL ");
        for(struct DQNode *n = queue->front; n != NULL; n = n->next) {
            printf("-> %d ", n->key);
        }
        printf("-> NULL\n");
    }
}
