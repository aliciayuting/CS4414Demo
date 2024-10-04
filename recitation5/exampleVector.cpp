#include <iostream>

class MyIntVector {
public:
     std::size_t size;    // Number of elements in the vector
     int* data;           // Pointer to dynamically allocated array
    
     
     MyIntVector():size(0),data(nullptr){}

     
     MyIntVector(std::size_t size) : size(size), data(new int[size]) {
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

     ~MyIntVector(){
          std::cout << "In destructor. releasing data memory" << std::endl;
          delete[] data;
     }

};

MyIntVector foo(){
     MyIntVector vect1 = MyIntVector(5);
     std::cout << "vect1.data" << vect1.data << std::endl;
     MyIntVector vect2= MyIntVector(4);
     vect2 = vect1; // copy assignment operator .(opeartor =)
     
     std::cout << "vect2.data" << vect2.data << std::endl;

     std::cout << "----------" << std::endl;
     return vect2; 
}


int main() {
    MyIntVector vec1(5); // Create a vector of size 5
     MyIntVector ret = foo();
          std::cout << "ret.data" << ret.data << std::endl;

     std::cout << ret.data[0] << std::endl; // undefined behaviours

    return 0;
}
