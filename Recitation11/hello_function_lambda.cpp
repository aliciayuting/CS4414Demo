#include <iostream>
#include <thread>
#include <string>
#include <vector>

int main()
{
     // std::thread t([](std::string name)
     //               { std::cout << "Hello World ! " << name << " \n"; },
     //               "Alicia");
     // t.join();

     std::vector<int> v1 = {3, 1, 7, 9};
     std::vector<int> v2 = {10, 2, 7, 16, 9};
     // access v1 and v2 by reference
     auto pushinto = [&](int m)
     {
          v1.push_back(m);
          v2.push_back(m);
     };
     pushinto(100);
     for (auto i : v2)
     {
          std::cout << i << std::endl;
     }

     return 0;
}
