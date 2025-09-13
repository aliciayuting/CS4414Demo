#include <iostream>

int * memory_leak_func(){
    int* leakyArray = new int[100]; // Allocate memory for 1 Billion integers (~4GB each iteration)

    leakyArray[0] = 42;
     
    return leakyArray;
}

int main() {
    int* leak_arr;
    for (int i = 0; i < 10; i ++){
        leak_arr = memory_leak_func();
        // delete[] leak_arr;   // without this line, the code will cause memory leak
        std::cout << "Allocated memory on " << i << "*4GB" << std::endl;
    }
    
    return 0;
}
