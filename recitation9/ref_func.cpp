#include <thread>
#include <iostream>

void hello_count(std::string to, int x){
     x++;
     std::cout << "Hello to " << to << x << std::endl;
}
int main(){
     int x = 0;
     std::thread threadObj(hello_count, "alicia", x);  // what about not have std::ref()?
     threadObj.join();
     std::cout << "after hello_count x=" << x << std::endl;
     return 0;
}
