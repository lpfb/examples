#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack *createStack() {
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));

    s->size = 0;
    s->top = NULL;

    return s;
}

struct Node *createNode(int key) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void push(struct Stack *s, int key) {
    struct Node *newNode = createNode(key);

	if(s->size <= 0) {
		s->top = newNode;
	} else {
        newNode->next = s->top;
        s->top = newNode;
    }

    s->size++;
    return;
}


void pop(struct Stack *s) {
    if(s->size <= 0)
        return;

    struct Node *nodeToDelete = s->top;
    s->top = nodeToDelete->next;
    free(nodeToDelete);
}

void printStack(struct Stack *s) {
    struct Node *n = s->top;

    printf("(TOP) ");

    while(n != NULL) {
        printf("%d -> ", n->key);
        n = n->next;
    }
    printf("NULL\n");
}

int isEmpty(struct Stack *s) {
    if(s->size <= 0)
        return 1;

    return 0;
}

size_t size(struct Stack *s) {
    return s->size;
}
