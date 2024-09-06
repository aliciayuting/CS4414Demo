#include <iostream>

int main(){
     int32_t arr[5];
     for(int i = 0; i < 5; i++)
          arr[i] = i + 1;
     std::cout << "sizeof(arr)=" << sizeof(arr) << std::endl;
     std::cout << "sizeof(int32_t[5])=" << sizeof(int32_t[5]) << std::endl;
     std::cout << "sizeof(int32_t[5])/sizeof(int32_t)=" << sizeof(int32_t[5])/sizeof(int32_t) << std::endl;
     
     
     


     return 0;
}

#include <iostream>

int main(){
     // C-style fixed-size array
     int32_t arr[5];
     for(int i = 0; i < 5; i++)
          arr[i] = i + 1;

     // Check array size
     std::cout << "sizeof(arr)=" << sizeof(arr) << std::endl;
     std::cout << "sizeof(int32_t[5])=" << sizeof(int32_t[5]) << std::endl;
     std::cout << "sizeof(int32_t[5])/sizeof(int32_t)=" << sizeof(int32_t[5])/sizeof(int32_t) << std::endl;
     
     // Array pointer conversion
     int32_t* ptr = arr;
     for (int i=0; i<5; i++){
          std::cout << *ptr << ",";
          ptr ++;  // pointer arithmetics
     }
     std::cout << std::endl;

     // size of pointer that is converted from an array
     std::cout << "sizeof(ptr)=" << sizeof(ptr) << std::endl;

     return 0;
}