#include <iostream>
#include <thread>
#include <vector>
#include <memory>

void work(int id) {
     auto data = std::make_unique<int[]>(10000);  
     // int data[1000];
     for (int i = 0; i < 1000; ++i) {
          data[i] = id;  
     }
     std::cout << "Thread " << id << " completed work" << std::endl;
}

int main() {
     std::vector<std::thread> threads;

     for (int i = 0; i < 5; ++i) {
          threads.emplace_back(work, i);  
     }


     std::cout << "Main function is exiting without joining threads" << std::endl;
     for (int i=0; i < 5; ++i){
          threads[i].join();
     }
    // Threads go out of scope here, and their destructors will call std::terminate
    return 0;
}