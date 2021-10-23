#include <iostream>


// class declaration: normally in hpp file
template<typename T>
class fraction {
private:
    T num;
    T denom;
public:
    fraction() {};
    fraction(T my_num, T my_denom): num(my_num), denom(my_denom){};
    fraction &operator+=(fraction const &other);
    void print_frac();
};

// class implementation: in cpp file
template <typename T>
fraction<T> &fraction<T>::operator+=(fraction const &other){
        this->num += other.num * denom + num * other.denom;
        this->denom += other.denom * denom;
        //... more computations to simplify the fraction
        return *this;
}

template <typename T>
void fraction<T>::print_frac(){
        std::cout << num << "/" << denom << std::endl;
}



int main(){
    
    fraction<int> frac;
    fraction<int> frac1(3, 7);
    fraction<int> frac2(4, 2);

    frac1 += frac2;
    frac1.print_frac();

    return 0;
}