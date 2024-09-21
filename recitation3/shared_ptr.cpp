#include "class/rectangle.hpp"
#include <memory>
#include <iostream>

std::shared_ptr<Rectangle> foo(){
     std::shared_ptr<Rectangle> rec_ptr = std::make_shared<Rectangle>();
     return rec_ptr;
}


void foo2(){
     std::shared_ptr<Rectangle> rec_ptr2 = foo();
     std::cout << "finish foo, generated rec_ptr2" << std::endl;
     std::shared_ptr<Rectangle> rec_ptr3 = rec_ptr2;
     std::cout << "assigned rec_ptr2 to rec_ptr3" << std::endl;
}



int main(){
     // after main() function finishes, the shared pointers go out of scope, and the destructor of Rectangle gets called
     foo2();
     std::cout << "finished foo2 function" << std::endl;
}