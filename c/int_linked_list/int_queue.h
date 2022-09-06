#include <stdio.h>
#include <stdlib.h>

struct QNode {
    int key;
    struct QNode *next;
};

struct Queue {
    struct QNode *front, *rear;
    size_t size;
};

// Private functions
struct Queue *createQueue();
struct QNode *createNode(int key);

// API start
void enQueue(struct Queue *queue, int key);
void deQueue(struct Queue *queue);
int isEmpty(struct Queue *queue);
void printQueue(struct Queue *queue);
