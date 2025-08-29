
#include <vector>
#include <iostream>


int main(){
     // std::vector initialization
     std::vector<int> vect = {1,2,3};
     vect.push_back(4);
     vect.push_back(5);
     std::cout << "size of vect : " << vect.size() << std::endl;
     std::cout << "capacity of vect: " << vect.capacity() << std::endl;

     vect.reserve(1024); // now the capacity is 1024, while the size remains 5 unchanged

     std::cout << "size of vect : " << vect.size() << std::endl;
     std::cout << "capacity of vect: " << vect.capacity() << std::endl;

     std::vector<int>::iterator itr;
     for (itr = vect.begin(); itr != vect.end(); itr++){
          std::cout << *itr << std::endl;
     }


     return 0;
}