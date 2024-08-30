#include <iostream>

int main() {
     // sizeof(<type>)  
     std::cout << "Size of bool: " << sizeof(bool) << " byte(s)" << std::endl;
     std::cout << "Size of char: " << sizeof(char) << " byte(s)" << std::endl;
     std::cout << "Size of int: " << sizeof(int) << " bytes(s)" << std::endl;
     // sizeof(variable name) 
     double x = 3.14;
     std::cout << "Size of double: " << sizeof(x) << " byte(s)" << std::endl;
     int32_t y = 123456;
     std::cout << "Size of int32_t: " << sizeof(y) << " byte(s)" << std::endl;
     uint8_t z = 10;
     std::cout << "Size of uint8_t: " << sizeof(z) << " bytes(s)" << std::endl;
     return 0;
}
