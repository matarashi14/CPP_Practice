#include <iostream>

#include "sort.h"

int main()
{
    srand(time(0));
    Sort s1;

    Sort s2(10);

    std::cout << s1;
    std::cout << s2;

    std::cout << "Max is " << s2.getMax() << ": Min is " << s2.getMin() << std::endl;

    s2.radixSort();

    std::cout << s2;

    return 0;
}