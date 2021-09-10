#include <iostream>
#include "numberQueue.h"


void numberQueue::addElement(std::uint32_t myInt, std::string myString){
    myQueue.push({myInt, myString});
}

void numberQueue::popAllElements(){
    while(!myQueue.empty()){
        std::cout << std::to_string(myQueue.front().first) << myQueue.front().second << "\n";
        myQueue.pop();
    }
}