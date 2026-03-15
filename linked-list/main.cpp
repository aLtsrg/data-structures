#include <iostream>
#include "linked-list.h"

void printLL(LinkedList& ll)
{
    LinkedList::Node *current = ll.begin();

    std::cout << "-> ";

    while(current != nullptr){
        std::cout << "[" << current->value << "] -> ";
        current = current->next;
    }

    std::cout << "nullptr\n";
}

int main()
{

    LinkedList lst;

    for (int i{}; i <100; ++i){
        lst.push_back(i); 
    }

    printLL(lst);

    lst.reverse();

    printLL(lst);


    return 0; 
}
