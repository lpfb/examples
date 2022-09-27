#include <stdlib.h>

struct Node {
    int key;
    struct Node *next;
};

struct Stack {
    struct Node *top;
    size_t size;
};

struct Stack *createStack();
void push(struct Stack *s, int key);
void pop(struct Stack *s);
void printStack(struct Stack *s);
int isEmpty(struct Stack *s);
size_t size(struct Stack *s);
