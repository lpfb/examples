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
void pushQueue(struct Queue *queue, int key);
void popQueue(struct Queue *queue);
void insertQueue(struct Queue *queue, int index, int key);
void deleteQueue(struct Queue *queue, int index);
int isEmpty(struct Queue *queue);
void printQueue(struct Queue *queue);
