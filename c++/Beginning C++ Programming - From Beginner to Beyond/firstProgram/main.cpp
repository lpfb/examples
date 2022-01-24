#include <iostream>

using namespace std;

int main() {
    cout << "Before boolalpha: ";
    cout << (100 == 100) << endl;
    cout << boolalpha; // enable true and false print
    cout << "After boolalpha: ";
    cout << (100 == 100) << endl;
    cout << noboolalpha; // disable true and false print

    return 0;
}
