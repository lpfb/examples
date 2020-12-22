#include <iomanip>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(void) {
    cout << "Teste" << endl;

    for(int i = 0; i < 20; i++) {
        cout << "\rProgres: " << i*100/19 << flush;
        usleep(300*1000);
    }
    cout << endl;
    
    return 0;
}
