#include <iostream>
using namespace std;

int main() {
    const int  LENGTH = 10; // It is a good practive to define constants in CAPITALS
    const int  WIDTH  = 5;
    const char NEWLINE = '\n';
    int area;  

    area = LENGTH * WIDTH;
    cout << area;
    cout << NEWLINE;
    return 0;
}
