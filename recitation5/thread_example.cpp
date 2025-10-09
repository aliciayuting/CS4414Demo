#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <chrono>

// std::thread foo(){
//     std::vector<int> a = {1,2,3,5};
//     std::thread threadObj([&](){
//         for (int i : a){
//             std::cout << i << std::endl;
//             std::this_thread::sleep_for(std::chrono::seconds(1));
//         }
//     });

//     return threadObj;
// }


// // fix 1 move vector inside thread
// std::thread foo(){
    
//     std::thread threadObj([](){
//         std::vector<int> a = {1,2,3,5};
//         for (int i : a){
//             std::cout << i << std::endl;
//             std::this_thread::sleep_for(std::chrono::seconds(1));
//         }
//     });

//     return threadObj;
// }

// fix 2 use heap
std::thread foo() {
    // shared_ptr to C-style array; uses delete[] automatically
    // std::shared_ptr<int[]> arr(new int[5]{1,2,3,4,5});
    std::shared_ptr<int[]> arr(new int[5]{1,2,3,4,5},std::default_delete<int[]>());

    // Move ownership into the thread so lifetime extends until thread ends
    return std::thread([arr]() { // capture by value
        for (int i = 0; i < 5; ++i) {
            std::cout << arr[i] << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });
}


/***
 * Suppose I want to have my main thread to end the foo() thread 
 * after printing "Back to main function"
 */

int main(){
    std::thread obj= foo();
    
    
    std::cout << "Back to main function" << std::endl;
    obj.join();

    return 0;
}