#include <iostream>
 

// function to generate and retrun an array.
int * getArray( ) {
   static int  r[10];
   
   for (int i = 0; i < 10; ++i) {
      r[i] = i;
   }
 
   return r;
}
 
// main function to call above defined function.
int main () {
   // a pointer to an int.
   int *p;
 
   p = getArray();
   for ( int i = 0; i < 10; i++ ) {
      std::cout << "*(p + " << i << ") : ";
      std::cout << *(p + i) << std::endl;
   }
 
   return 0;
}