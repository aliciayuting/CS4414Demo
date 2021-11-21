#include <iostream>
#include <functional>
#include <thread>
#include <future>
int main()
{
     std::promise<int> my_promise;
     std::future<int> my_future = my_promise.get_future();
     std::function<void(std::promise<int> &&)> run = [](std::promise<int> &&my_promise)
     {
          int x;
          std::cin >> x;
          my_promise.set_value(x);
     };
     std::thread worker(run, std::move(my_promise));
     std::cout << "Waiting for the worker thread to fulfill its promise" << std::endl;
     int result = my_future.get();
     std::cout << "Result produced is: " << result << std::endl;
     worker.join();
}

// don't need the global data struture,
// every member will have a map and it is transported to other thread through promise and future
