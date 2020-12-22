#include <iostream>
#include <string>

using namespace std;

template <typename T> T Add (T a, T b) { 
   return a + b;
}

int main () {
   int i = 39;
   int j = 20;

   cout << "Add(i, j): " << Add(i, j) << endl; 

   string s1 = "Teste";
   string s2 = " 123";

   cout << "Concatenation of Strings Add(i, j): " << Add(s1, s2) << endl; 

   return 0;
}
