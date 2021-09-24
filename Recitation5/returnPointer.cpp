#include <iostream>

// Buggy code
int * count()
{
    int myInt = 5;

    int * const p = &myInt;

    return p;
}

int main(){
    std::cout << "Value is " << *count() << std::endl;
}