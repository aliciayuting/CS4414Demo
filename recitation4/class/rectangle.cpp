#include "rectangle.hpp"
// Implementation file for Rectangle class
#include <iostream>

Rectangle::Rectangle():
               width(0), length(0), area(0)
{    
     pixels = nullptr; // Initialize pointer to null
     std::cout << "In default constructor" << std::endl;
}

// Parameterized constructor
Rectangle::Rectangle(float w, float l):
               width(w),length(l)
{
     area = w * l;
     pixels = new float[static_cast<int>(w * l)]; // allocate array on heap
     std::cout << "In parameterized constructor, width=" << w << ",length=" << l << std::endl;
}

// Copy constructor
Rectangle::Rectangle(const Rectangle& other): width(other.width), length(other.length), area(other.area){
     if (other.pixels) {
          pixels = new float[static_cast<int>(other.width * other.length)];
          std::copy(other.pixels, other.pixels + static_cast<int>(other.width * other.length), pixels);
     } else {
          pixels = nullptr;
     }
     std::cout << "Copy constructor is called" << std::endl;
}

// Move constructor
Rectangle::Rectangle(Rectangle&& other)  
        : width(other.width), length(other.length), area(other.area) {
     std::cout << "Move Constructor Called" << std::endl;
     other.width = 0;
     other.length = 0;
     other.area = 0;
     pixels = other.pixels; // Steal the resource
     other.pixels = nullptr; // Leave other in a safe state
    }

// Copy assignment operator
Rectangle& Rectangle::operator=(const Rectangle& other) {
     std::cout << "Copy Assignment Operator Called" << std::endl;
     if (this == &other)
          return *this; // Self-assignment check
     width = other.width;
     length = other.length;
     area = other.area;
     if (pixels) {
          delete[] pixels; // Free existing resource
     }
     if (other.pixels) {
          pixels = new float[static_cast<int>(other.width * other.length)];
          std::copy(other.pixels, other.pixels + static_cast<int>(other.width * other.length), pixels);
     } else {
          pixels = nullptr;
     }
     return *this;
}

// Move assignment operator
Rectangle& Rectangle::operator=(Rectangle&& other)  {
     std::cout << "Move Assignment Operator Called" << std::endl;
    if (this != &other) { // Check for self-assignment
          // Transfer ownership of the data from 'other' to 'this'
          width = other.width;
          length = other.length;
          area = other.area;

          other.width = 0;
          other.length = 0;
          other.area = 0;
          if (pixels) {
               delete[] pixels; // Free existing resource
          }
          pixels = other.pixels; // Steal the resource
          other.pixels = nullptr; // Leave other in a safe state
    }
    return *this; 
}

bool Rectangle::operator<(const Rectangle& other) const {
     std::cout << "opeartor < is called" << std::endl;
    return this->area < other.area;
}

// Destructor
Rectangle::~Rectangle()
{
     if (pixels) {
          delete[] pixels; 
     }
     std::cout << "In Rectangle destructor" << std::endl;
}

float& Rectangle::getArea(){
     return area;
}

void Rectangle::printRectangle(){
     std::cout << "Rectangle object, width=" << width << ",length="<< length << ",area" << area << std::endl;
}
