#include <iostream>
#include "dynamic-array.h"

int main()
{
    DynamicArray<int> da{};


    for (int i{}; i < 17; ++i){
        da.push_back(i);
        std::cout << "---------------------------------------\n";
        std::cout << "SIZE: " << da.getSize() << '\n';
        std::cout << "CAPACITY: " << da.getCapacity() << '\n';
    }

    std::cout << da.back() << '\n';

    std::cout << "Hello, World!\n";
    return 0;
}
