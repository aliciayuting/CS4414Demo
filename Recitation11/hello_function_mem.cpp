#include <iostream>
#include <thread>
#include <string>

class Hello
{
public:
     void greeting(std::string const &message) const
     {
          std::cout << message << std::endl;
     }
};

int main()
{
     SayHello x;
     std::thread t(&SayHello::greeting, &x, "hello");
     t.join();
}