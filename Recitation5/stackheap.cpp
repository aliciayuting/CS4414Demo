#include <iostream>
#include <string>

class Test{

}


int main()
{
    int value = 5;  // stack allocation
    int array[5];
    Test test;

    int* hvalue = new int;     // heap allocation
    *hvalue = 5;
    int* harray = new int[5];
    Test htest = new Test();

}