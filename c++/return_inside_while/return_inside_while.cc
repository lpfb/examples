#include <iostream>

int main() {
    int i = 0;

    do {
        i++;
        if(i == 15)
            return i;
    } while(i < 70);
    return 0;
}
