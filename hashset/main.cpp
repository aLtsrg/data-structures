#include <iostream>
#include "hashset.h"

int main()
{

    HashSet<int> hs{};

    std::cout << "SIZE:     " << hs.getSize() << '\n'; 
    std::cout << "CAPACITY: " << hs.getSize() << '\n'; 
    
    hs.add(100);
    hs.add(100);
    hs.add(200);
    hs.add(101010);
    hs.add(-2782);

    hs.printHashSet();

    int N { 15 };
    for (int i {1}; i < N; ++i){
        hs.add(i);
        std::cout << "-------------------------------------\n";
        std::cout << "SIZE:     " << hs.getSize() << '\n';
        std::cout << "CAPACITY: " << hs.getCapacity() << '\n';
    }

    
    hs.printHashSet();

    for (int i { N }; i > 0 ; --i){
        std::cout << "-------------------------------------\n";
        std::cout << "DELETION SUCCESFUL? " << hs.del(i) << '\n';
        std::cout << "SIZE:     " << hs.getSize() << '\n';
        std::cout << "CAPACITY: " << hs.getCapacity() << '\n';
    }

    hs.printHashSet();
    return 0;
}
