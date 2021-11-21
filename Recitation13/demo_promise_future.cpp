//reference: std::future and std::prommise : https://www.youtube.com/watch?v=XDZkyQVsbDY

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>

void doWork(std::promise<int> &&promiseObj)
{
     std::this_thread::sleep_for(std::chrono::seconds(10));
     promiseObj.set_value(42);
}

int main()
{
     std::promise<int> pObj;

     std::future<int> fObj = pObj.get_future();

     std::thread thread_A(doWork, std::move(pObj));
     std::cout << "Thread created!" << std::endl;
     // std::this_thread::sleep_for(std::chrono::seconds(10));
     std::cout << "About to get ... " << std::endl;
     std::cout << "Future get: " << fObj.get() << std::endl;
     std::cout << "Finished get ... " << std::endl;
     thread_A.join();
     return 0;
}