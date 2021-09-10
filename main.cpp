#include "numberQueue.h"

int main()
{
    numberQueue testQueue;

    for (int i = 0; i < 10; i++){
        std::string num_str = "This number is ";
        num_str += std::to_string(i);
        testQueue.addElement(i, num_str);
    }

    testQueue.popAllElements();

    return 0;
}