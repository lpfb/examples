#include <stdio.h>
#include "fifo.h"

void debug_print(circ_buf_t *f) {
    printf("\n===========================================\n");
    printf("Fifo Head index: %d\n", f->head);
    printf("Fifo Tail index: %d\n", f->tail);

    printf("Is Empty? %d\n", isFifoEmpty(f));

    printf("\n");
    printFifo(f);
    printf("===========================================\n\n");
}

// Driver Program to test above functions
int main() {
    CREATE_FIFO(fifo_st, 5);

    initFifo(&fifo_st);

    debug_print(&fifo_st);

    uint32_t data;

    for(int i = 1; i < 6; i++) {
        data = i;
        printf("Pushing %d into FIFO\n", data);

        if(fifoPush(&fifo_st, data))
            printf("ERROR: Out of space");
        debug_print(&fifo_st);
    }

    for(int i = 1; i < 6; i++) {
        printf("Poping data from FIFO\n");

        if(fifoPop(&fifo_st, &data))
            printf("ERROR: Fifo is empty");
        else
            printf("Poped %d\n", data);

        debug_print(&fifo_st);
    }

    for(int i = 10; i < 15; i++) {
        data = i;
        printf("Pushing %d into FIFO\n", data);

        if(fifoPush(&fifo_st, data))
            printf("ERROR: Out of space");
        debug_print(&fifo_st);
    }

    return 0;
}
