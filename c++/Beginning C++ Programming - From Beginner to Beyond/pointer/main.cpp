#include <iostream>
#include <vector>

using namespace std;

int main() {
    int var {10};
    int *var_ptr {&var};

    cout << "-----------------------------------------------------------------" << endl;
    cout << "Using int variable. But this is valid for any \"simple\" variable (int, double, string and etc)" << endl << endl;

    cout << "Var value: " << var << endl;
    cout << "Var address: " << &var << endl;
    cout << "Ptr value: " << var_ptr << endl; // Will display var address
    cout << "Ptr dereferencing: " << *var_ptr << endl; // Will display var value

    cout << "\nChanging var value through the pointer" << endl;
    *var_ptr = 200;

    cout << "Var value: " << var << endl;
    cout << "Var address: " << &var << endl;
    cout << "Ptr value: " << var_ptr << endl; // Will display var address
    cout << "Ptr dereferencing: " << *var_ptr << endl; // Will display var value

    cout << "\n-----------------------------------------------------------------" << endl;
    cout << "Using pointer to Array and accessing its elements" << endl << endl;

    int int_array[] {50, 60, 200, -1};
    int *int_array_ptr {int_array}; // Does not need and & because int_array already points to its first item memory address

    /* There are two ways to accesses a array content, both using pointer and an array itself, they are:
     * Subscript notation:
     * -> array_name[index]
     * -> pointer_name[index]
     * Offset notation:
     * -> *(array_name+index)
     * -> *(pointer_name+index)
     */

    // IMPORTANT: the array, without any index will point to its first element address:
    cout << "int_array value (no index = address): " << int_array << endl;
    cout << "int_array_ptr value (sames as above): " << int_array_ptr << endl << endl;

    cout << "Subscript notation: " << endl;
    cout << "First array element value of pointer " << int_array_ptr[0] << endl; // Accessing first element
    cout << "First array element address: " << &int_array_ptr[0] << endl;
    cout << "Secound array element value of pointer: " << int_array_ptr[1] << endl; // Accessing second element
    cout << "Secound array element address of pointer: " << &int_array_ptr[1] << endl; // The address will be *(int_array_ptr+0) + 4(integer byte size)

    cout << "\nOffset notation: " << endl;
    cout << "First array element value of pointer " << *int_array_ptr << endl; // Accessing first element
    cout << "First array element address: " << int_array_ptr << endl;
    cout << "Secound array element value of pointer: " << *(int_array_ptr+1) << endl; // Accessing second element
    cout << "Secound array element address of pointer: " << (int_array_ptr+1) << endl; // The address will be *(int_array_ptr+0) + 4(integer byte size)

    cout << "\nUsing arith ++ and -- to point to next and previous pointer position: " << endl;
    cout << "First array element value of pointer " << *int_array_ptr << endl; // Accessing first element
    cout << "First array element address: " << int_array_ptr << endl;
    cout << "Getting next array element: int_array_ptr++" << endl;
    int_array_ptr++; // Now the pointer is pointing to next element of the array
    cout << "Secound array element value of pointer: " << *int_array_ptr << endl; // Accessing second element
    cout << "Secound array element address of pointer: " << int_array_ptr << endl; // The address will be *(int_array_ptr+0) + 4(integer byte size)
    cout << "Getting previous array element: int_array_ptr--" << endl;
    int_array_ptr--; // Now the pointer is pointing to previous element of the array
    cout << "First array element value of pointer " << *int_array_ptr << endl; // Accessing first element
    cout << "First array element address: " << int_array_ptr << endl;

    cout << "Loop through the array until find sentinel value (-1)" << endl;
    cout << "Method 1:" << endl;
    while(*int_array_ptr != -1) {
        cout << *int_array_ptr << endl;
        int_array_ptr++;
    }

    int_array_ptr = int_array; // Pointing to first element again

    cout << "Method 2:" << endl;
    while(*int_array_ptr != -1)
        cout << *int_array_ptr++ << endl;


    cout << "\n-----------------------------------------------------------------" << endl;
    cout << "Using pointer to vector to access values and iterate over pointer" << endl << endl;
    vector<string> names {"Luis", "Paulo", "Fernandes"};
    vector<string> *names_ptr {nullptr};

    names_ptr = &names;

    cout << "dereferencing *names_ptr to get names firt value" << endl;
    cout << "First name: " << (*names_ptr).at(0) <<  endl;
    // This can be read as:
    // (*names_ptr).at(0) -> (*names_ptr) returns "names" vector
    //  names      .at(0)
    // First, names_ptr pointer needs to be deferenced "*names_ptr" inside a "()", in order to be executed prior to try to access vector contents using .at(), at this point you have "names" vector, than use .at(0) to get names first value

    // Ranged loop
    cout << "\nIterating with the pointer using ranged loop" << endl;
    for(auto name: *names_ptr) // Here, *names_ptr can be read as "names"
        cout << name << endl;

    return 0;
}
