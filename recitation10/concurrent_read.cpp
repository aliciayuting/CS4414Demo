/***
 * Example where race condition does not happens for multithreading program on std::vector
 * The reason is that there are multiple reads at the same time, but no write, so it is thread-safe.
 */
#include <iostream>
#include <vector>
#include <thread>

void read_vector(const std::vector<double>& vec, int thread_id, double& sum) {
    for (const auto& value : vec) {
        sum += value;  // Each thread reads the vector and accumulates the sum
    }
}

int main() {
     std::vector<double> vec(1000000, 1.00);

     double t1_sum;
     double t2_sum;
     std::thread t1(read_vector, std::ref(vec), 1, std::ref(t1_sum));
     std::thread t2(read_vector, std::ref(vec), 2, std::ref(t2_sum));

     t1.join();
     t2.join();

     std::cout << "t1_sum="<< t1_sum << ",t2_sum=" << t2_sum << std::endl;
    std::cout << "Both threads have finished reading the vector." << std::endl;

    return 0;
}
