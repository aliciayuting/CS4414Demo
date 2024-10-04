#include <iostream>

class Counter {
public:
    static int count;  
    Counter() {
        ++count;
    }
};

int Counter::count = 0;

int main() {
    Counter c1;
    std::cout << "Number of Counter objects created: " << Counter::count << std::endl;
    return 0;
}
