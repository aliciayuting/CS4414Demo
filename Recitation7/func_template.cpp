#include <iostream>
#include <string>

void print(int value){
    std::cout << value << std::endl;
}

void print(std::string value){
    std::cout << value << std::endl;
}

int main(){
    print(5);
    print("hello world");
    return 0;
}


// template<typename T>
// void print(T value){
//     std::cout << value << std::endl;
// }

// // print(5);
// void print(int value){
//     std::cout << value << std::endl;
// }

// // print(5.5f);
// void print(float value){
//     std::cout << value << std::endl;
// }