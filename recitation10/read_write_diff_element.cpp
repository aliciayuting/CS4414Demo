/***
 * Example of false sharing for multithreading program 
 * Concurrent writes on different elements that are in the same cache line
 */
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

constexpr size_t NUM_THREADS = 4;
constexpr size_t INCREMENTS = 1000;

// Function to repeatedly increment a specific element in the vector
void increment_value(std::vector<double>& vec, size_t index) {
    for (size_t i = 0; i < INCREMENTS; ++i) {
        vec[index]++;
    }
}

int main() {
    // Initialize a vector with NUM_THREADS elements, each set to 0
    std::vector<double> vec(NUM_THREADS, 0.0);

    // Create threads that will increment adjacent elements in the vector
    std::vector<std::thread> threads;
    auto start_time = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(increment_value, std::ref(vec), i);
    }

    // Join threads
    for (auto& t : threads) {
        t.join();
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;

    // Print the results
    for (size_t i = 0; i < NUM_THREADS; ++i) {
        std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
    }

    std::cout << "Time taken with potential false sharing: " << duration.count() << " seconds\n";

    return 0;
}
