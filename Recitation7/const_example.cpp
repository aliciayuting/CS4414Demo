#include <iostream>


class Coordinate
{
private:
    int myX, myY;
    mutable int var;

public:
    // this method doesn't modify the class fields
    int getX() const{
        // myX = 2;   // does not work
        // var = 3;
        return myX;
    }
};

void printX(const Coordinate& c){
    std::cout << c.getX() << std::endl;
}

int main(){
    int MAX_VAL = 100;
    int* a = new int;
    *a = 3;
    const int* b = a;
    *b = 2;
    b = &MAX_VAL;
    std::cout << *b << std::endl;
    *a = 4;
    std::cout << *b << std::endl;

    // Coordinate example;
    // printX(example);

    return 0;
}