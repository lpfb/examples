#include <iostream>
#include <string>
#include "my_string.h"

using namespace std;

int main() {
    Mystring s1 {"teste"};
    Mystring s2;

    cout << "S1: " << s1.get_string() << endl;
    cout << "S2 before copy: " << s2.get_string() << endl;

    s2 = s1;

    cout << "S2 after copy: " << s2.get_string() << endl;

    return 0;
}
