#include <iostream>
using namespace std;


void fill_data(int *data) {
    *data = 30;
    cout << "Addr: " << data << endl;
};

int main() {
    int data = 0;

    fill_data(&data);

    cout << "Data: " << data << endl;

    return 0;
}
