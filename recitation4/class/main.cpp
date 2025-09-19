#include "rectangle.hpp"
#include <memory>
#include <iostream>
#include <memory>


void foo(){
     // Stack allocated two Rectangle objects
     Rectangle original(5.0, 6.0);
     Rectangle move_original(std::move(original));
     std::cout << "move_original width: " << move_original.width << std::endl;
     std::cout << "original width: " << original.width << std::endl;


     // There is only one Rectangle object on the heap
     std::unique_ptr<Rectangle> original_ptr = std::make_unique<Rectangle>(5.0, 6.0);
     std::unique_ptr<Rectangle> original_ptr2 = std::move(original_ptr);

     std::cout << "-------------------" << std::endl;
}


int main(){
     foo();
     std::cout << "Back to main function" << std::endl;

     return 0;

}