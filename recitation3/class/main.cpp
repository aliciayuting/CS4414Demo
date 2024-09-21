#include "rectangle.hpp"
#include <memory>
#include <iostream>

std::shared_ptr<Rectangle> foo(){
     std::shared_ptr<Rectangle> rec_ptr = std::make_shared<Rectangle>();
     return rec_ptr;
}

int main(){

     std::shared_ptr<Rectangle> rec_ptr2 = foo();
     std::cout << "finish foo1, generated rec_ptr2" << std::endl;
     std::shared_ptr<Rectangle> rec_ptr3 = rec_ptr2;

     std::cout << "finish foo2, generated rec_ptr3" << std::endl;


}


// pointer

// heap 

// unique_ptr

// shared_ptr
