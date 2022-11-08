#ifndef _FIFO_H_
#define _FIFO_H_

#include <stdint.h>

#define CREATE_FIFO(x,y)           \
    uint32_t x##_data_space[y];    \
    circ_buf_t x = {               \
        .buffer = x##_data_space,  \
        .head = 0,                 \
        .tail = 0,                 \
        .maxlen = y                \
    }

typedef struct {
    int head;
    int tail;
    int maxlen;
    uint32_t *const buffer;
} circ_buf_t;

int ciclePointer(circ_buf_t *f, int *next_ptr);
void initFifo(circ_buf_t *f);
int fifoPush(circ_buf_t *f, uint32_t data);
int fifoPop(circ_buf_t *f, uint32_t *data);
int isFifoEmpty(circ_buf_t *f);
void printFifo(circ_buf_t *f);

#endif
