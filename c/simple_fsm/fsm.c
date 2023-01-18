#include <stdio.h>
#include <unistd.h> // Delay
#include "fsm.h"

int periph_config(void) {
    return SUCCESS;
};

int write_register(void) {
    return SUCCESS;
};

int read_register(void) {
    return SUCCESS;
};

int return_status(void) {
    return SUCCESS;
};


// FSM Task
void controlFsmTask(void) {
    enum States state = IDLE;
    int end = 0;

    while(!end) {
        switch(state) {
            case IDLE:
                printf("IDLE\n");
                fflush(stdin);
                state = CHECK_PACKET;
                break;
            case CHECK_PACKET:
                printf("CHECK_PACKET\n");
                fflush(stdin);
                state = PERIPH_CONFIG;
                break;
            case PERIPH_CONFIG:
                printf("PERIPH_CONFIG\n");
                fflush(stdin);
                state = WRITE_REGISTER;
                break;
            case WRITE_REGISTER:
                printf("WRITE_REGISTER\n");
                fflush(stdin);
                state = READ_REGISTER;
                break;
            case READ_REGISTER:
                printf("READ_REGISTER\n");
                fflush(stdin);
                state = RETURN_STATUS;
                break;
            case RETURN_STATUS:
                printf("RETURN_STATUS\n");
                fflush(stdin);
                end = 1;
                break;
            default:
                break;
        }

        sleep(1);
    }
};

