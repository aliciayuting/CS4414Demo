#pragma once
#include "A.hpp"

struct A;

struct B {
    // A a;   // by-value member requires full definition of A here
    A* a; // by-pointer member works
    void hello();
};