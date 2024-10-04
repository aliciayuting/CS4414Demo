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

     MyIntVector(const MyIntVector& other) : size(other.size), data(new int[other.size]) {
          for (std::size_t i = 0; i < size; ++i) {
               data[i] = other.data[i];
          }
     }

    MyIntVector(MyIntVector&& other) noexcept : size(0), data(nullptr) {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }

    MyIntVector& operator=(const MyIntVector& other) {
        if (this == &other) {
            return *this; 
        }
        delete[] data;
        size = other.size;
        data = new int[size];
        for (std::size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    MyIntVector& operator=(MyIntVector&& other) noexcept {
        if (this == &other) {
            return *this; 
        }
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
        return *this;
    }

    // Destructor to free the allocated memory
    ~MyIntVector() {
        delete[] data;
    }

     int& operator[](std::size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds.");
        }
        return data[index];
    }


    // Function to print the elements of the vector
    void print() const {
        std::cout << "MyIntVector elements: [";
        for (std::size_t i = 0; i < size; ++i) {
            std::cout << data[i];
            if (i < size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

};

