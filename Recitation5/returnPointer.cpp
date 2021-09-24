#include <iostream>
#include <array>

// Buggy code
int* test () {
   int c[5];
   for (int i = 0; i < 5; i++) 
          c[i] = i;
   return c;
}


int main(){
    int * result = test();
    std::cout << "Value is " << result[0] << std::endl;
}












// Fix1
// std::array<int,5> test () {
//    std::array<int,5> c;
//    for (int i = 0; i < 5; i++) 
//           c[i] = i;
//    return c;
// }


// int main(){
//     std::array<int,5> result = test();
//     std::cout << "First Value is " << result[0] << std::endl;
// }


// Fix2.
// int* test () {
//    int* c = new int[5];
//    for (int i = 0; i < 5; i++) 
//           c[i] = i;
//    return c;
// }