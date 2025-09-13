#include <iostream>

void func(int* x, int y){
    *x = 5;
    y = y + *x;
    x = &y;
    *x = *x + 10;
}

int main(){
    int x = 0;
    int y = 10;
    func(&x, y);
    std::cout << "x is " << x << std::endl;
    return 0;
}