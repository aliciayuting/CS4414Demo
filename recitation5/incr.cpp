#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

// // Fix1 use atomic
// std::atomic<int> counter = 0;  

// void add(int increment) {
//      for (int i = 0; i < increment; ++i) {
//         //   counter = counter + 1;// doesn't work because =.. +.. is not atomic operation
//             counter += 1;
//      }
// }

// Fix2 use mutex
int counter = 0;
std::mutex counter_mutex;

void add(int increment) {
    counter_mutex.lock();
     for (int i = 0; i < increment; ++i) {
          
          counter += 1;
     }
    // counter_mutex.unlock();
}


int main() {

        std::thread t1(add,100000);
        std::thread t2(add,100000);
        std::thread t3(add,100000);

        t1.join();
        t2.join();
        t3.join();


         std::cout << "Final counter value: " << counter << std::endl;

     return 0;
}