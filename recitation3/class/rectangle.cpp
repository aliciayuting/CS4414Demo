#include "rectangle.hpp"
// Implementation file for Rectangle class
#include <iostream>

Rectangle::Rectangle():
               width(0), length(0), area(0)
{
     std::cout << "In default constructor" << std::endl;
}


Rectangle::Rectangle(float w, float l):
               width(w),length(l)
{
     area = w * l;
     std::cout << "In parameterized constructor, width=" << w << ",length=" << l << std::endl;
}

Rectangle::Rectangle(const Rectangle& other): width(other.width), length(other.length), area(other.area){
     std::cout << "Copy constructor is called" << std::endl;
}

Rectangle::Rectangle(Rectangle&& other)  
        : width(other.width), length(other.length), area(other.area) {
        std::cout << "Move Constructor Called" << std::endl;
        other.width = 0;
        other.length = 0;
        other.area = 0;
    }

Rectangle& Rectangle::operator=(const Rectangle& other) {
        std::cout << "Copy Assignment Operator Called" << std::endl;
        if (this == &other)
            return *this; // Self-assignment check
        width = other.width;
        length = other.length;
        area = other.area;
        return *this;
}

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
    }
    return *this; 
}

bool Rectangle::operator<(const Rectangle& other) const {
     std::cout << "opeartor < is called" << std::endl;
    return this->area < other.area;
}

Rectangle::~Rectangle()
{
     // std::cout << "In Rectangle destructor" << std::endl;
}

float& Rectangle::getArea(){
     return area;
}

void Rectangle::printRectangle(){
     std::cout << "Rectangle object, width=" << width << ",length="<< length << ",area" << area << std::endl;
}
