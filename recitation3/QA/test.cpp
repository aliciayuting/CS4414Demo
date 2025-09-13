
// // NOT working solution
// struct B;

// struct A {
//     B b;   // needs full definition of B
// };

// struct B {
//     A a;   // needs full definition of A
// };

// int main(){
//     return 0;
// }


// // Working solution1
struct B;

struct A {
    B* b;   // use pointer
};

struct B {
    A a;   //  A is already defined
};

int main(){
    return 0;
}


// // Working solution2
// struct B;

// struct A {
//     B* b;   // use pointer
// };

// struct B {
//     A* a;   //  use pointer for both
// };

// int main(){
//     return 0;
// }
