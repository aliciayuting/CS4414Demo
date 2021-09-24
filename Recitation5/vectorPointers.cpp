/***
 * Reference : https://medium.com/@arpytoth/the-dangerous-pointer-to-vector-a139cc42a192 
 */

#include <iostream>
#include <vector>
int main()
{
 std::vector<int> intVector;
 intVector.push_back(1);
 
 // We get the pointer to the first element from our vector.
 int* pointerToInt = &intVector[0];
 std::cout << "The value of our int is: " << *pointerToInt << std::endl;
 
 intVector.push_back(2);
 intVector.push_back(3);
 std::cout << "The value of our int is: " << *pointerToInt << std::endl;
return 0;
}