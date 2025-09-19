#pragma once
// Header file for class Rectangle
class Rectangle{
public:
	float width;
	float length; 
	float area;
	float* pixels; // dynamically allocated array

	Rectangle();
	Rectangle(float w, float l);

	Rectangle(const Rectangle& other);
	Rectangle(Rectangle&& other);
	Rectangle& operator=(const Rectangle& other);
	Rectangle& operator=(Rectangle&& other);
	bool operator<(const Rectangle& other) const;
	~Rectangle();

	float& getArea();
     void printRectangle();
};
