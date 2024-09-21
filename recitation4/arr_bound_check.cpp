#include <iostream>
#include <array>

       


int main(){

   // C-style array
   int arr_p[5] = {1,2,3,4,5};
   
   // arr is now a pointer to the first element of the array
   int* arr = arr_p;
   // this arr_size will not return the size of array (5), as intended
   size_t arr_size = sizeof(arr) / sizeof(int); // pointer size 8 byte, int size 4 byte on x86_64
   for(int i = 0; i < arr_size; ++ i){	 
      std::cout << arr[i] << std::endl;
   }

   // C-style array don't have bound check
   // this line could be compiled, but it is now accessing memory out of bound, causing undefined behaviour
   std::cout << arr_p[20] << std::endl; 

   // std::array -- a better way to store array
   std::array<int, 5> s_array;
   std::cout << "size of s_array = " << s_array.size() << std::endl;
   /*** below line is out of bound accessing, 
    * running it will see terminate called after throwing an instance of 'std::out_of_range'
    * Above error is more helpful than undefined behaviour, as it can help to locate the issue in the code
    */
   std::cout << s_array.at(20) << std::endl;

   return 0;
}