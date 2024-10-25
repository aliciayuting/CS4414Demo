#include <iostream>
#include <thread>

int main() {
    int value = 10;
    std::cout << "Initial value: " << value << std::endl;
    std::thread t([&]() {
        value += 5;
        std::cout << "Value in lambda: " << value << std::endl;
    });

    t.join();
    std::cout << "Final value: " << value << std::endl;
    return 0;
}