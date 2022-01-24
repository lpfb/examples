#include <iostream>

using namespace std;

int main() {
    int *array_ptr {nullptr};
    int size {};

    cout << "How big do you want the array?" << endl;
    cin >> size;

    array_ptr = new int[size]; // Now we have an array of 10 integers size allocated in memory

    delete [] array_ptr; // Frees allocated memory

    return 0;
}
