#include <memory>
#include <iostream>
#include "class/rectangle.hpp"



void foo(){

     // create an unique_ptr for a Rectangle object on heap
     std::unique_ptr<Rectangle> ptr = std::make_unique<Rectangle>(10.0, 11.0);

     // Transfer of ownership
     // // below line is incorrect. Because unique_ptr cannot be copied to another unique_ptr variable
     // std::unique_ptr<Rectangle> ptr2 = ptr;  

     // below line is the correct way of transfer the ownership of unique_ptr
     // after this line, ptr is now nullptr
     std::unique_ptr<Rectangle> ptr2 = std::move(ptr);

     // Releasing memory managed by unique_ptr, either 1 or 2 below would release the memory
     // 1. calling reset()
     ptr2.reset(); 

     // 2. when unique_ptr object is out of scoped
     // after foo function finishes, destructor of the Rectangle object gets called
}

     

int main(){

     foo();
     std::cout << "foo function finished" << std::endl;
     return 0;

}    