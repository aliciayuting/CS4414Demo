/*** This example is eferencing from : 
 * https://www.geeksforgeeks.org/queue-of-pairs-in-c-stl-with-examples/ 
 * */

#ifndef NUMBERQUEUE_H
#define NUMBERQUEUE_H

#include <string>
#include <queue>
#include <bits/stdc++.h>

class numberQueue{

public:

    std::queue<std::pair<std::uint32_t, std::string>> myQueue;

    void addElement(std::uint32_t, std::string);

    void popAllElements();
    
};

#endif