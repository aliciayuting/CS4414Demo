#include <thread>
#include <iostream>

class myClass{
public:
    int x;
    myClass(int _x): x(_x){}
    void print(){
        std::cout << "myClass.x="<< x << std::endl;
    }
};

int main(){
     myClass m1(1);
     std::thread t1(&myClass::print, &m1);
     t1.join();
     return 0;
}