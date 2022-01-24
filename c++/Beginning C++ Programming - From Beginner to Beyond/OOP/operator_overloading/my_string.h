#include <iostream>
#include <string>

class Mystring{
    //Attributes
    private:
        char *str;

    public:
        // Constructors
        Mystring(); // No-args
        Mystring(const char *c); // One-arg
        // Copy constructor
        Mystring(const Mystring &source); // Copy constructor
        // Destructor
        ~Mystring();

        // Methods
        char *get_string();
        Mystring &operator=(const Mystring &rhs);
};
