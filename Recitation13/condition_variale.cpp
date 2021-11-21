//referencing example in this tutorial:
// https://www.youtube.com/watch?v=eh_9zUNmTig

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::condition_variable my_cv;
std::mutex m;
long balance = 0;

void addMoney(int money)
{
     std::scoped_lock<std::mutex> lg(m);
     balance += money;
     std::cout << "Amount Added Current Balance: " << balance << std::endl;
     my_cv.notify_one();
}

void withdrawMoney(int money)
{
     std::unique_lock<std::mutex> lck(m);
     my_cv.wait(lck, []
                { return (balance != 0) ? true : false; });
     if (balance >= money)
     {
          balance -= money;
          std::cout << "Amount deducted: " << money << std::endl;
     }
     else
     {
          std::cout << "Amount Can't be deducted, current blance is less than " << money << std::endl;
     }
     std::cout << "Current balance is: " << balance << std::endl;
}

int main()
{
     std::thread t1(withdrawMoney, 500);
     std::this_thread::sleep_for(std::chrono::seconds(10));
     std::thread t2(addMoney, 500);
     t1.join();
     t2.join();
     return 0;
}