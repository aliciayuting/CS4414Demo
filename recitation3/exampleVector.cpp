#include <iostream>

class MyIntVector {
public:
     std::size_t size;    // Number of elements in the vector
     int* data;           // Pointer to dynamically allocated array
    
     
     MyIntVector():size(0),data(nullptr){}

     
     MyIntVector(std::size_t size) : size(size), data(new int[size]) {
          std::cout << "In size constructor" << std::endl;
          for (std::size_t i = 0; i < size; ++i) {
               data[i] = 0;
          }
     }

     // copy constructor.
     MyIntVector(const MyIntVector& other):size(other.size),data(new int[other.size]){
          for(int i = 0 ; i < other.size; i ++){
               data[i] = other.data[i];
          }
          std::cout << "In copy constructor" << std::endl;
     }

     // Copy assignment (deep copy)
     MyIntVector& operator=(const MyIntVector& other) {
          std::cout << "In copy assignment operator" << std::endl;
          if (this == &other) return *this;
          int* newData = other.size ? new int[other.size] : nullptr;
          for (std::size_t i = 0; i < other.size; ++i) newData[i] = other.data[i];
          delete[] data;
          data = newData;
          size = other.size;
          return *this;
     }


     ~MyIntVector(){
          std::cout << "In destructor. releasing data memory" << std::endl;
          delete[] data;
     }

};


// function pass by value, copy constructor is called
void test_value_parameter(MyIntVector vec){
     std::cout << "Testing pass by value, vec size:" << vec.size << "." << std::endl;
}


int main() {
     // MyIntVector vec1(5); // Create a vector of size 5
     std::cout << "vect1.data" << vect1.data << std::endl;
     MyIntVector vect2= MyIntVector(4);
     vect2 = vect1; 
     std::cout << "vect2.data" << vect2.data << std::endl;
     // test_value_parameter(vec1);
     MyIntVector ret = test_value_return();
     // std::cout << "ret.data" << ret.data << std::endl;
     
     return 0;
}
