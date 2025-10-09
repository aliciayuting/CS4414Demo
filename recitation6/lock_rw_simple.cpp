/*** Read/Write lock implementaion1
 * Simple read write lock via shared_mutex and shared_lock
 * Noted if read_vector() function is continuously been called, 
 * then it may cause write_vector() to be blocked and starved
 */
#include <shared_mutex>
#include <mutex>
#include <iostream>
#include <thread>

int global_val = 0;
std::shared_mutex global_mutex;



int main(){
     int local_val=10;
     int local_val2=10;
     std::cout << "before local val=" << local_val << std::endl;

     std::thread readThread([&local_val](){
          std::shared_lock<std::shared_mutex> readLock(global_mutex);
          local_val = global_val;
     });

     std::thread readThread2([&local_val2](){
          std::shared_lock<std::shared_mutex> readLock(global_mutex);
          local_val2 = global_val;
     });

     std::thread writeThread([](){
          std::unique_lock<std::shared_mutex> writeLock(global_mutex);
          global_val ++;
     });

     readThread.join();
     readThread2.join();
     writeThread.join();
     std::cout << "after local val=" << local_val << std::endl;
     std::cout << "Finish increment" << std::endl;
     return 0;
}