#include <iostream>
#include <thread>
#include <string>

class Hello
{
public:
     Hello()
     {
          std::cout << "In default constructor" << std::endl;
     }
     // Overload () operator
     void operator()(std::string name)
     {
          std::cout << "Hello to " << name << std::endl;
     }
};

int main()
{
     std::thread t(Hello(), "alicia");
     t.join();
     return 1;
}
