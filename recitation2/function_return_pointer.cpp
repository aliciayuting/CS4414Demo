#include <iostream>
// Use gdb to debug

// Below are examples that incorrectly return pointers by functions

// Dangling pointer: local variable. 
int* dangerousFunction(){
     // int localVar = 100;
     static int localVar = 100;
     return &localVar;
}


// int arr[5] = {1,2,3,4,5}; 

int* arrayFunc(int index){
     // int arr[5] = {1,2,3,4,5}; 
     //  fix1. use heap , but need to call delete[] after finish using this object
     int* arr = new int[5]{1,2,3,4,5}; 
     //  fix2. use global or static variable arr
     // static int arr[5] = {1,2,3,4,5}; 
     //  fix3. create arr outside of this function, and pass in arr as parameter
     return &arr[index];
}


int main(){
     // local variable
     int* res = dangerousFunction();
     std::cout <<  "dangerousFunction return pointer is: " << res << std::endl; 
     // Segmentation fault, because dangling pointer
     std::cout <<  "dangerousFunction return value is: " << (*res) << std::endl;  

     // local array variable
     int* arr_res = arrayFunc(3);
     std::cout << "arr_res= " << arr_res << std::endl;
     // Segmentation fault, for the same reason
     std::cout << "*arr_res=" << (*arr_res) << std::endl;

     return 0;
}


