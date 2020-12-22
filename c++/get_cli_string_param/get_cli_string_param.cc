#include <iostream>
#include <vector>
#include <string>
#include<string.h>

int GetParameterstr(int argc, char **argv, const char *param, char **value)
{
    uint16_t index = 0;

    if(argc < 2 || argv == NULL || param == NULL)
    {
        return -1;
    }

    uint16_t max = argc - 1;
    // if (value == NULL)
    //     max = argc;

    for(index = 0; index < max; index++)
    {
        if(strcmp(argv[index], param) == 0)
        {
            if (value != NULL) {
                std::cout << "Parameter found!!!!!!!" << (char *)argv[index + 1] << std::endl;
                *value = argv[index + 1];
            }
            return 0;
        }
    }
    return -1;
}

int main(int argc, char **argv) {
    const char param[] = "--file";
    char *value;
    std::cout << "Iniciando" << std::endl;
    GetParameterstr(argc, argv, param, &value);
    std::cout << "Returned value: " << value << std::endl;
    return 0;
}
