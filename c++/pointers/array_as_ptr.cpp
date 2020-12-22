#include <iostream>
using namespace std;


void fill_array(int *arr, long int arr_size) {
    for(int i = 0; i < arr_size; i++) {
        *(arr+i) = i;
    }
};

int main() {
    int arr[5];

    printf("Array size: %ld\n", sizeof(arr)/sizeof(int));
    cout << endl;

    fill_array(arr, sizeof(arr)/sizeof(int));

    for(int i = 0; i < 5; i++) {
        printf("Array value: %d\n", arr[i]);
    };
    cout << endl;

    for(int i = 0; i < 5; i++) {
        cout << "Array addr: " << arr + i << endl;
    };
    cout << endl;

    cout << "Array base address (arr): " << arr << endl;
    cout << "Array base address (&arr[0]): " << &arr[0] << endl;
    cout << endl;
    cout << "Value base address value: " << *arr << endl;
    cout << "Value secound value: " << *(arr+1) << endl;

    return 0;
}
