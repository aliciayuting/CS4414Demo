#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <atomic>

std::atomic<int> number = 0;

void increment(int times)
{
     for (int i = 0; i < times; i++)
     {
          number++; //= number + 1;
     }
}

int main(int argc, char *argv[])
{

     int total_threads = 1;
     if (argc >= 2)
     {
          total_threads = std::stoi(argv[1]);
     }

     std::vector<std::thread> threadList;
     for (int thread_nums = 0; thread_nums < total_threads; thread_nums++)
     {
          threadList.push_back(std::thread(increment, 100000));
     }
     std::cout << "wait for all the worker thread to finish" << std::endl;
     std::for_each(threadList.begin(), threadList.end(), std::mem_fn(&std::thread::join));
     std::cout << "Final result, number=" << number << std::endl;
     return 0;
}
