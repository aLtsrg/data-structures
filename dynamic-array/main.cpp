#include <iostream>
#include "dynamic-array.h"
#include "dynamic-array-int.h"
#include <vector>



int main()
{
    DynamicArray<int> da;


    for (int i{}; i < 30; ++i){
        da.push_back(i);

        std::cout << " ---------------------- \n";
        std::cout << "CAPACITY: " << da.capacity() << std::endl;
    }

    std::cout << "SIZE: " << da.size() << std::endl;
    da.resize(40);
    std::cout << "SIZE: " << da.size() << std::endl;

    for (size_t i {}; i < da.size(); ++i){
        std::cout << "[ ";
        std::cout << da[i] << " ";
        std::cout << "]\n";
    }

    std::cout << da.capacity() << '\n';



    return 0;
}
