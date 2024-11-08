/***
 * Example where race condition happens for multithreading program on std::vector
 * Concurrent read and write lead to race condition
 * To fix this, could use mutex as we learnt in recitation 11.
 */
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

constexpr size_t NUM_INSERTS = 10;

// Function for the writer thread to add elements to the vector
void writer(std::vector<int>& vec) {
    for (int i = 0; i < NUM_INSERTS; ++i) {
        vec.push_back(i);  // Add element to the vector
        std::this_thread::sleep_for(std::chrono::milliseconds(50));  // Slow down insertion
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3};  // Initialize vector with initial values

    // Start the writer thread to modify the vector
    std::thread t1(writer, std::ref(vec));   // Thread 1 writes to the vector

    // Lambda for the reader thread to access vec.back() (NOT thread-safe)
    std::this_thread::sleep_for(std::chrono::milliseconds(10));  // Small delay to let writer start
    std::thread t2([&vec]() {
        // Attempt to read vec.back() concurrently, which is not thread-safe
        try {
            std::cout << "Reading from vec.back(): " << vec.back() << std::endl;
        } catch (...) {
            std::cout << "Exception caught while accessing vec.back()\n";
        }
    });

    // Join threads
    t1.join();
    t2.join();

    // Print the final values in the vector for reference
    std::cout << "Final vector values: ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
