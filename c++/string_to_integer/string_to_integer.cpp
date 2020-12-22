#include <iostream>
#include <vector>

int main() {
    std::string tmp = "55.10";
    uint16_t temperature; 

    std::cout << "String temp: " << tmp << std::endl;
    temperature = static_cast<uint16_t>(std::stof(tmp)*100);
    std::cout << "Int temp: " << temperature << std::endl;
   return 0;
}
