#include <iostream>
#include "dynamic-array.h"
#include <vector>



int main()
{
    DynamicArray<int> da;


    for (int i{}; i < 17; ++i){
        da.push_back(i);
    }

    da.reserve(1000000);

    for (size_t i {}; i < da.size(); ++i){
        std::cout << da[i] << '\n';
    }

    std::cout << da.capacity() << '\n';



    return 0;
}
