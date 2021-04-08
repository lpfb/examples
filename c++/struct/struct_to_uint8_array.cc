#include <iostream>
#include <vector>

#pragma pack(1) // Used to avoid byte padding and mantain the exact structure size and layout
typedef struct {
    uint8_t id;
    uint32_t teste;
} str_test;
#pragma pack()

int main() {
    std::cout << "Iniciando" << std::endl;
    str_test teste;
    teste.id = 32;
    teste.teste = 1024;

    printf("ID: %d, Teste: %d\n", teste.id, teste.teste);

   uint8_t *data = (uint8_t *) &teste;
   printf("data0: %d, data1: %d, data2: %d, data3: %d, data4: %d\n", data[0], data[1], data[2], data[3], data[4]);
   return 0;
}
