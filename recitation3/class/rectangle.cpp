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

Rectangle::~Rectangle()
{
     std::cout << "In Rectangle destructor" << std::endl;
}

float& Rectangle::getArea(){
     return area;
}

void Rectangle::printRectangle(){
     std::cout << "Rectangle object, width=" << width << ",length="<< length << ",area" << area << std::endl;
}
