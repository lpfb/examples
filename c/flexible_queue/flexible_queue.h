#include <stdio.h>
#include <stdlib.h>

struct QNode {
    char *data;
    size_t data_size;
    struct QNode *next;
};

struct Queue {
    struct QNode *front, *rear;
    size_t size;
};

// Private functions
struct Queue *createQueue();
struct QNode *createNode(char *data, size_t data_size);

// API start
void append(struct Queue *queue, char *data, size_t data_size);
void pop(struct Queue *queue);
void insertIndex(struct Queue *queue, int index, char *data, size_t data_size);
void removeIndex(struct Queue *queue, int index);
void reverse(struct Queue *queue);
int isEmpty(struct Queue *queue);
