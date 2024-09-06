#include <iostream>


// 1. local variable, an example that incorrectly use function return reference
int& add(int a, int b){
     int c = a + b;
     return c;
}

int main(){
     int first = 1;
     int second = 2;
     int& sum = add(first, second);
     // segmentation fault
     std::cout << "sum is " << sum << std::endl; 
     return 0;
}


// // 2. reference to array element, an example that correctly return reference
// int& getElement(int arr[], int index){
//      return arr[index];
// }

// int main(){
//      int numbers[5]={1,2,3,4,5};
//      int& element = getElement(numbers, 3);
//      element = 0;
//      for (int i = 0; i < 5 ; i ++){
//           std::cout << numbers[i] << " ";
//      }
//      std::cout << std::endl;
//      return 0;
// }