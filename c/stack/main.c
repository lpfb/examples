#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void debug_print(struct Stack *s) {
    printf("\n===========================================\n");
    if(s->top!= NULL)
        printf("Stack top: %d\n", s->top->key);
    else
        printf("Stack top: NULL\n");

    printf("Stack size: %ld\n", size(s));
    printf("Is Empty? %d\n", isEmpty(s));

    printf("\n");
    printStack(s);
    printf("===========================================\n\n");
}

int main() {
    struct Stack *stack = createStack();
    int key;

    debug_print(stack);
    key = 10;
    printf("push %d\n", key);
    push(stack, key);
    debug_print(stack);

    key = 5;
    printf("push %d\n", key);
    push(stack, key);
    debug_print(stack);

    key = 30;
    printf("push %d\n", key);
    push(stack, key);
    debug_print(stack);

    printf("pop\n");
    pop(stack);
    debug_print(stack);

    printf("pop\n");
    pop(stack);
    debug_print(stack);

    printf("pop\n");
    pop(stack);
    debug_print(stack);

    free(stack);

    return 0;
}
