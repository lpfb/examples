#include <stdio.h>
#include "fifo.h"

void initFifo(circ_buf_t *f) {
    for(int i = 0; i < f->maxlen; i++)
        f->buffer[i] = 0;
}

int ciclePointer(circ_buf_t *f, int *next_ptr) {
    int next;

    next = *next_ptr + 1;

    if(next >= f->maxlen) // Cicle buffer pointer
        return 0; // Pointer cicled

    return next;
}

int fifoPush(circ_buf_t *f, uint32_t data) {
    int next;

    next = ciclePointer(f, &f->head);

    if (next == f->tail) // FULL?
        return -1; // Error

    f->buffer[f->head] = data;
    f->head = next;

    return 0; // Success
}

int fifoPop(circ_buf_t *f, uint32_t *data) {
    int next;

    if(isFifoEmpty(f))
        return -1;

    next = ciclePointer(f, &f->tail);

    *data = f->buffer[f->tail];
    f->tail = next;              // tail to next offset.

    return 0;  // return success to indicate successful push.
}

int isFifoEmpty(circ_buf_t *f) {
    if (f->head == f->tail)  // Empty?
        return 1;

    return 0;
}

void printFifo(circ_buf_t *f) {
    for(int i = 0; i < f->maxlen; i++) {
        printf("[%d]:%d", i, f->buffer[i]);

        if(i != f->maxlen-1)
            printf(" - ");
    }
    printf("\n");
}
