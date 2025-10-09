#include <iostream>
#include <thread>
#include <vector>
#include <memory>

void foo(int id) {
     int* data = new int[1000];
     for (int i = 0; i < 1000; ++i) {
          data[i] = id;  
     }
     std::cout << "Thread " << id << " completed work" << std::endl;
}

// fix1 call delete
// buggy program
void work_fix1(int id) {
     // int* data = new int[10000];
     std::unique_ptr<int[]> data = std::make_unique<int[]>(10000);
     for (int i = 0; i < 10000; ++i) {
          data[i] = id;  
     }
     // delete[] data;  // release memory
     std::cout << "Thread " << id << " completed work" << std::endl;
}



// fix2 use shared_ptr
void work_fix2(int id) {
     std::unique_ptr<int[]> dataPtr(new int[1000], std::default_delete<int[]>());
     for (int i = 0; i < 1000; ++i) {
          dataPtr.get()[i] = id;  
     }
     std::cout << "Thread " << id << " completed work" << std::endl;
}

int main() {
     std::vector<std::thread> threads;

     for (int i = 0; i < 5; ++i) {
          threads.emplace_back(work_fix2, i);  
     }
     for (int i = 0; i < 5; ++i){
          threads[i].join();
     }

     std::cout << "Main function is exiting" << std::endl;
    return 0;
}




