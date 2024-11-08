#include <iostream>
#include <mutex>
#include <thread>

std::mutex global_mutex;
int global_val = 0;

void incre(){
     global_mutex.lock();
     global_val ++;
     global_val = global_val/0;
     global_mutex.unlock();
}

int main(){

     std::thread t1(incre);
     // global_mutex.unlock();
     std::thread t2(incre);
     // global_mutex.unlock();

     t1.join();
     t2.join();

     std::cout << "Finish increment" << std::endl;
     return 0;
}