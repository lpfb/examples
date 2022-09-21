#include <stdio.h>
#include <stdlib.h>

struct DQNode {
    int key;
    struct DQNode *next;
    struct DQNode *previous;
};

struct DQueue {
    struct DQNode *front, *rear;
    size_t size;
};

// Private functions
struct DQueue *createDQueue();
struct DQNode *createNode(int key);

// API start
void append(struct DQueue *queue, int key);
void pop(struct DQueue *queue);
void insertIndex(struct DQueue *queue, int index, int key);
void removeIndex(struct DQueue *queue, int index);
int isEmpty(struct DQueue *queue);
void printDQueue(struct DQueue *queue, int reverse);
