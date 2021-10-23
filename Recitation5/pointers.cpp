/**
 * @file pointers.cpp
 * @author Alicia 
 * @ref https://en.cppreference.com/w/cpp/memory/shared_ptr 
 * @date 2021-09-23
 * 
 */
#include <iostream>
#include <thread>
#include <time.h>

class Example{
public:
    Example()
    {
        std::cout << "Created an Example! " << std::endl;
    }

    ~Example(){
        std::cout << "Destroyed an Example! " << std::endl;
    }

    void print_hey(){
        std::cout << "Hey I'm an example! " << std::endl;
    }
};

// void continue_fn(){
//     int c = 0;
//     time.sleep(10000);
//         // while(c<1000){
//         //     c++;
//         // }
//     }

int main()
{
    // raw pointer
    // Example* example = new Example();
    // std:: cout << example << std::endl;
    // // delete example;
    // // std::thread sleep_t(continue_fn);
    // // sleep_t.join();

    // // Copy the pointed-to object by dereferencing the pointer
    // // to access the contents of the memory location.
    // // mc is a separate object, allocated here on the stack
    // Example example2 = *example;

    // // Declare a pointer that points to example using the addressof operator
    // Example* ecopy = &example2;

    

    // Smart pointer, (also explain scope)
    {
        // unique_ptr constructor explicit
        // std::unique_ptr<Example> example = new Example();
        std::unique_ptr<Example> example2(new Example());
        std::unique_ptr<Example> example3 = std::make_unique<Example>();
        // std::unique_ptr<Example> copy_example = example;
    }

    return 0;
}
