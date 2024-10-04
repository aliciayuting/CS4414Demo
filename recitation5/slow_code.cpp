#include "myVector.hpp"
#include <vector>

void addVectorsSlowly(std::vector<MyIntVector>& vec_list, int size) {
     
     vec_list.emplace_back(size);   
}

int main() {
     std::vector<MyIntVector> vec_list;
     for (int i = 0; i< 10000000; i++){
          // MyIntVector new_vec(10);
          addVectorsSlowly(vec_list, 10);
     }
    return 0;
}