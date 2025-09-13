#include <vector>

class myClass {
private:
     int myInt;
public:
    myClass(int my_int): myInt(my_int){}
};

int main(){
    std::vector<myClass> myObjects();
    return 0;
}

