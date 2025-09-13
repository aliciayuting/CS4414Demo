#include <iostream>

int subtract(int a, int b){
	return a-b;
}



template <typename T>
T subtract(T a, T b) {
     std::cout << "templated" << std::endl;
    return a - b;
}

template <typename T>
class Subtracter {
public:
    T subtract(T a, T b) {
        return a - b;
    }
};


int main(){
	int x = 10;
	int y = 7;
	std::cout << subtract(x, y) << std::endl;   // int 3

    double p = 5.5;
    double q = 2.2;

    
    std::cout << subtract(p, q) << std::endl;   // double 3.3


//     Subtracter<int> int_sub;
//     Subtracter<double> double_sub;

//     std::cout << int_sub.subtract(10, 7) << std::endl;     // 3
//     std::cout << double_sub.subtract(5.5, 2.2) << std::endl; // 3.3
}
