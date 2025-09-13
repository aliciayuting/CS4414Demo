#pragma once
#include "B.hpp"

struct B;

struct A {
    // B b;   // by-value member requires full definition of B here
              // or if only one of them(A and B) by-value, also works, checkout test.cpp

    B* b;   // by-pointer member works.
    void hello();
};