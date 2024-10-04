#include "myVector.hpp"
#include <vector>

// This optimization implementation come from the ideas by Parker and Evan in our recitation discussions 

/***
 * @param vec_list passing by reference, which can save copy the vec_list object
 * @param size an argument used to construct MyIntVector object in-place
 * @return void, not returning anything, because we are directly edit on the vec_list object passed in
 */
void addVectorsFast(std::vector<MyIntVector>& vec_list, int size) {
     vec_list.emplace_back(size);   // construct object in-place
}

int main() {
     std::vector<MyIntVector> vec_list;
     // pre-reserve space, could help std::vector from keep allocating new memories on heap when the size of the vector exceeds its capacity
     vec_list.reserve(10000);  // Reserve space but don't initialize elements
     for (int i = 0; i< 10000; i++){
          addVectorsFast(vec_list, 10);
     }
     std::cout << vec_list.size() << std::endl; // check if the vec_list was correctly added

     return 0;
}