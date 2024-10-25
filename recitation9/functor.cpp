#include <iostream>
#include <thread>

class Printer {
    int value;
public:
    Printer(int v) : value(v) {}
    
    void operator()() const {
        std::cout << "Functor with value: " << value << std::endl;
    }
};

int main() {
    Printer printer(30);

    std::thread t(printer);

    t.join();
    return 0;
}
