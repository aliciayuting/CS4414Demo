#include "myVector.hpp"
#include <vector>

/*** You can time the program by running $ time ./myexec , which will display the runtime
 *  A fun activity would be run this slow_code and run fast_cost implementation, 
 *  and you can find a over 200 times speed up if we fixed the copies we called 
*/

/***
 * @param vec_list object is passing as value, which creates copies of the object
 * @param vec is passing in as a value, which create a copy of MyIntVector
 * @return vec_list is a copy on return. the returned vec_list is a copy of the vec_list objects
*/
std::vector<MyIntVector> addVectorsSlowly(std::vector<MyIntVector> vec_list, MyIntVector vec) {
     vec_list.push_back(vec);   // copy constructor is called by push_back, which is time-costly
     return vec_list;
}

int main() {
     std::vector<MyIntVector> vec_list;
     for (int i = 0; i< 10000; i++){
          MyIntVector new_vec(10);
          std::vector<MyIntVector> added_vec_list = addVectorsSlowly(vec_list,new_vec);
          vec_list = added_vec_list; // copy assignment is called, another time-consuming extra copy
     }
     std::cout << vec_list.size() << std::endl; // check if the vec_list was correctly added
    return 0;
}

