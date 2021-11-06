#include <iostream>
#include <thread>
#include <string>

void hello(std::string hello_to)
{
     std::cout << "Hello Concurrent World to " << hello_to << "\n";
}

void hello_count(std::string to, int &x)
{
     // int &y = const_cast<int &>(x);
     x++;
     std::cout << "Hello to " << to << x << std::endl;
}

int main()
{
     // std::thread t1(hello, "alicia");
     // std::thread t2(hello, "sagar");
     // t1.join();
     // t2.join();

     int x = 0;
     std::thread threadObj(hello_count, "alicia", std::ref(x));
     threadObj.join();
     std::cout << "After thread x=" << x << std::endl;
     return 1;
}
