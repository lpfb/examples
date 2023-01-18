enum ReturnStatus {
    SUCCESS,
    ERROR
};

enum States {
    IDLE = 0,
    CHECK_PACKET,
    PERIPH_CONFIG,
    WRITE_REGISTER,
    READ_REGISTER,
    RETURN_STATUS
};

// FSM States
int periph_config(void);
int write_register(void);
int read_register(void);

// FSM Task
void controlFsmTask(void);
