#include <stdio.h>

struct test {
    int i;
    char c;
};

void test(char *teste) {
    printf("Mensagem: %s\n", teste);
}

int test_int_pointer_and_return(int data, int *result) {
    *result = data;

    return data+1;
}

void test_struct(struct test t) {
    printf("Teste i: %d\n", t.i);
    printf("Teste c: %c\n", t.c);
}
