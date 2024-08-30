#include <iostream>

int main(){

     // Correct way of using address and pointer
     double x = 0.0;   // create a variable of type double
     std::cout << "x value: x = " << x << std::endl;
     std::cout << "x address: &x = " << &x << std::endl;
     double* px = &x;  // create a pointer of type double, that points to the address of x
     std::cout << "px value: px = " << px << std::endl;
     std::cout << "The value at the memory address os px ix: *px = " << *px << std::endl;  
     std::cout << "&px = " << &px << std::endl;   // print out the address of px

     /*** Incorrect way of using uninitialized variables 
      * Below is an example of using uninitialized pointer object, then causing runtime errors.
     */
     int* a_ptr;
     // // The line below causes a compile time Warning, for using an uninitialized value
     // std::cout << "Pointer a_ptr = " << a_ptr << std::endl;   
     // // The line below causes a runtime Segmentation fault. 
     // // Because it is dereferencing an uninitizlied value
     // std::cout << "Value at a_ptr is *a_ptr=" << *a_ptr << std::endl;
     // // The line below also causes a segmentation fault, for the same reason
     // *a_ptr = 100;
     return 0;

}