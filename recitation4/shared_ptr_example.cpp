#include "class/rectangle.hpp"
#include <memory>
#include <iostream>


void foo(std::shared_ptr<Rectangle> rec_ptr){
     rec_ptr->width = 200.0;
}


int main(){
 
    std::shared_ptr<Rectangle> rec = std::make_shared<Rectangle>(10.0, 11.0);
    std::shared_ptr<Rectangle> rec2 = rec;
    /*** This example to show that both rec and rec2 shared_ptr points to the same object.
     *   changes to anyone of them would reflect from both shared_ptr
     */
    rec2->width = 100.0; 
    rec->printRectangle();
    foo(rec);
    rec2->printRectangle();

     

    return 0;

}    