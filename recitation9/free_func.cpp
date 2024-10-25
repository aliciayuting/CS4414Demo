#include <thread>
#include <iostream>
void hello(std::string to)
{
     std::cout << "Hello Concurrent World to " << to << "\n";
}

int main(){
     std::thread t1( &hello, "alicia");
     std::thread t2( hello, "jonathan");
     t1.join();
     t2.join();
     return 0;
} 
