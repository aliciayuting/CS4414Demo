#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <algorithm>

std::vector<int> my_vec;
std::mutex my_mutex;

void vec_add(int new_value)
{
     std::scoped_lock<std::mutex> guard(my_mutex);
     my_vec.push_back(new_value);
}

void vec_contains(int value_to_find)
{
     std::scoped_lock<std::mutex> guard(my_mutex);
     bool contain = std::find(my_vec.begin(), my_vec.end(), value_to_find) != my_vec.end();
     std::cout << "value: " << value_to_find << " in my_vec: " << contain << std::endl;
}

int main()
{
     std::thread t_add1(vec_add, 1);
     std::thread t_add2(vec_add, 2);
     std::thread t_add3(vec_add, 3);
     std::thread t_contains(vec_contains, 3);
     t_add1.join();
     t_add2.join();
     t_add3.join();
     t_contains.join();
     return 0;
}