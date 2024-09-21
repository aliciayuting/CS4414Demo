#pragma once
// Header file for class Rectangle
class Rectangle{
public:
	float width;
	float length; 
	float area;

	Rectangle();
	Rectangle(float w, float l);
	~Rectangle();
	float& getArea();
     void printRectangle();
};
