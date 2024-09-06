#include <iostream>

int main(){

     // demonstrate reference 2 properties 
     int  x  = 0;
     int  y = 8;
     int& ref = x;
     ref = y;	

     std::cout << "x=" << x << std::endl;
     std::cout << "y=" << x << std::endl;
     std::cout << "ref=" << x << std::endl;
}