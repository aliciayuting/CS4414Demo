#include <iostream>
#include <thread>

std::atomic<int> counter = 0;  

void add(int increment) {
     for (int i = 0; i < increment; ++i) {
          counter += 1;
     }
     // int a = counter /0;
     throw 505;
}


int main() {
     try{
          std::thread t1(add,100000);
          std::thread t2(add,100000);
          std::thread t3(add,100000);

          t1.join();
          t2.join();
          t3.join();
     }catch (int myNum) {
          std::cout << "catching exceptions" << std::endl;
     }

     std::cout << "Final counter value: " << counter << std::endl;

     return 0;
}