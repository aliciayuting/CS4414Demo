#include <iostream>
#include <thread>
#include <vector>
#include <memory>

class MyClass {
public:
    MyClass(int id) : id(id) {
        std::cout << "MyClass object " << id << " created." << std::endl;
    }
    
    ~MyClass() {
        std::cout << "MyClass object " << id << " destroyed." << std::endl;
    }

    void doWork() {
        std::cout << "MyClass object " << id << " is working..." << std::endl;
    }

private:
    int id;
};

void work(int id) {
    auto obj = std::make_unique<MyClass>(id);

    obj->doWork();
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(work, i);  
    }

    std::cout << "Main function is exiting without joining threads." << std::endl;

    for (int i=0; i < 5; ++i){
          threads[i].join();
     }
    return 0;
}
