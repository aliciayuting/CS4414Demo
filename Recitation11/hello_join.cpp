#include <iostream>
#include <thread>

static bool is_Finished = false;

void hello()
{
     while (!is_Finished)
     {
          std::cout << "working ..." << std::endl;
     }
}

int main()
{
     std::thread worker(hello);

     // std::cin.get();

     // is_Finished = true;

     // worker.detach();
     return 1;
}