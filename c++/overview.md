# C++ Basics
This document is intended to be a quick C++ concept guide.

**Reference Materials**
- [Tutorial Spoint](https://www.tutorialspoint.com/cplusplus/cpp_overview.htm)

## Pointers
References:
- [tutorialspoint](https://www.tutorialspoint.com/cplusplus/cpp_pointers_vs_arrays.htm)

### Null pointer
It is always a good practice to assign the pointer NULL to a pointer variable in case you do not have exact address to be assigned. This is done at the time of variable declaration. A pointer that is assigned NULL is called a null pointer.

The NULL pointer is a constant with a value of zero defined in several standard libraries, including iostream.

```c
#include <iostream>

using namespace std;
int main () {
   int  *ptr = NULL;
   cout << "The value of ptr is " << ptr ;
 
   return 0;
}
```

To check for a null pointer you can use an if statement as follows. The value of null ptr is 0.
```c
if(ptr)     // succeeds if p is not null
if(!ptr)    // succeeds if p is null
```

### Pointer to array
Pointers and arrays are strongly related. In fact, pointers and arrays are interchangeable in many cases. For example, a pointer that points to the beginning of an array can access that array by using either pointer arithmetic or array-style indexing.

```c
#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main () {
   int  var[MAX] = {10, 100, 200};
   int  *ptr;

   // let us have array address in pointer.
   ptr = var;

   for (int i = 0; i < MAX; i++) {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;

      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;

      // point to the next location
      ptr++;
   }
   return 0;
}
```
However, pointers and arrays are not completely interchangeable. For example, consider the following program −

```c
#include <iostream>

using namespace std;
const int MAX = 3;

int main () {
   int  var[MAX] = {10, 100, 200};

   for (int i = 0; i < MAX; i++) {
      *var = i;    // This is a correct syntax
      var++;       // This is incorrect.
   }

   return 0;
}
```

It is perfectly acceptable to apply the pointer operator * to var but it is illegal to modify var value. The reason for this is that var is a constant that points to the beginning of an array and can not be used as l-value.

Because an array name generates a pointer constant, it can still be used in pointer-style expressions, as long as it is not modified. For example, the following is a valid statement that assigns var[2] the value 500 −

```c
*(var + 2) = 500;
```

Above statement is valid and will compile successfully because var is not changed.

The function which can accept a pointer, can also accept an array as shown in the following example.

```c
Live Demo

#include <iostream>
using namespace std;
 
// function declaration:
double getAverage(int *arr, int size);

int main () {
   // an int array with 5 elements.
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;

   // pass pointer to the array as an argument.
   avg = getAverage( balance, 5 ) ;

   // output the returned value
   cout << "Average value is: " << avg << endl;

   return 0;
}

double getAverage(int *arr, int size) {
   int i, sum = 0;
   double avg;

   for (i = 0; i < size; ++i) {
      sum += arr[i];
   }
   avg = double(sum) / size;

   return avg;
}
```

### Integer pointer
```c language
int  var = 20;   // actual variable declaration.
int  *ip;        // pointer variable 

ip = &var;       // store address of var in pointer variable

// print the memory address stored in ip pointer variable
cout << "Address stored in ip variable: ";
cout << ip << endl;

// access the value at the memory address available in pointer
cout << "Value of *ip variable: ";
cout << *ip << endl;
```
## Functions

### Return Pointer from Functions
It is not good idea to return the address of a local variable to outside of the function, so you would have to define the local variable as static variable.

Now, consider the following function, which will generate 10 random numbers and return them using an array name which represents a pointer i.e., address of first array element.

```c
#include <iostream>
#include <ctime>

using namespace std;

// function to generate and retrun random numbers.
int * getRandom( ) {
   static int  r[10];

   // set the seed
   srand( (unsigned)time( NULL ) );

   for (int i = 0; i < 10; ++i) {
      r[i] = rand();
      cout << r[i] << endl;
   }

   return r;
}

// main function to call above defined function.
int main () {
   // a pointer to an int.
   int *p;

   p = getRandom();
   for ( int i = 0; i < 10; i++ ) {
      cout << "*(p + " << i << ") : ";
      cout << *(p + i) << endl;
   }

   return 0;
}
```

### Template Functions
Templates are the foundation of generic programming, which involves writing code in a way that is independent of any particular type. A template is a blueprint or formula for creating a generic class or a function.


Below is the general form of a template function
```c
template <class type> ret-type func-name(parameter list) {
   // body of function
}
```

Example of use:
```c
template <typename T> inline T const& Max (T const& a, T const& b) { 
   return a < b ? b:a; 
}
```
Description:
- const&: Function arguments that contains this cannot be modified
- inline: used to copy this code to the line where Max(x, y) will be invoked. This improve speed due to the fact that function call overhead, the process of creating function stack and argument copy, for small functions is a bit heavy and replacing the line eliminate this.

### Arguments passing
There are three ways to pass arguments to a function, they are:
- Call by Value: This method copies the actual value of an argument into the formal parameter of the function. In this case, changes made to the parameter inside the function have no effect on the argument.
- Call by Pointer: This method copies the address of an argument into the formal parameter. Inside the function, the address is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.
- Call by Reference: This method copies the reference of an argument into the formal parameter. Inside the function, the reference is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument. **This method is preferred** over Call by pointer, because it is not possible to pass a null pointer, this will cause a compilation error.
