#include <cstring>
#include "my_string.h"

Mystring::Mystring()
    :str{nullptr} {
    // Constructor body
    str = new char[1];
    *str = '\0';
};

Mystring::Mystring(const char *c)
    :str{nullptr} {
    // Constructor body
    if (c == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(c) + 1];
        std::strcpy(str, c);
    }
};

Mystring::Mystring(const Mystring &source)
    :str{nullptr} {
    // Constructor body
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

Mystring::~Mystring() {
    // Destruconstructor body
    delete [] str;
}

char *Mystring::get_string() {
    return str;
}

Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Operator= called" << std::endl;
    if(this == &rhs) // Checking this is an autoassignment, ex: p1 = p1;
        return *this;

    delete [] str;

    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    return *this; // Returning the copy object
}
