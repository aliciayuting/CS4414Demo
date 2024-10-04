#include "rectangle.hpp"
#include <memory>
#include <iostream>



int main(){

     Rectangle rec1 = Rectangle(10.0, 11.0);
     Rectangle rec2 = rec1;

     Rectangle rec3 = std::move(rec1);
     bool compare = rec3 < rec2;
     std::cout << compare << std::endl;
     return 0;

}