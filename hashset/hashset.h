#ifndef HASHSET_H
#define HASHSET_H

#include <vector>
#include <functional>
#include <iostream>

template <typename T>
class HashSet
{
public:

    // member initializer list
    // look into this
    HashSet() : hashSet(capacity) {}

    bool add (const T& item)
    {
        //hash is not a function it is a type
        int hash { std::hash<T>{}(item) % capacity };

        if (exists(item, hash)) return false;

        hashSet[hash].push_back(item);
        ++size;

        if(size / static_cast<double>(capacity) >= loadFactor){
            rehash(2*capacity);
        }
        
        return true;
    }

    bool del (const T& item)
    {
        int hash { std::hash<T>{}(item) % capacity };
        for (int i{}; i < hashSet[hash].size(); ++i){
            if (hashSet[hash][i] == item){
                //quick remove
                //replace value with last value
                //remove duplicate
                hashSet[hash][i] = hashSet[hash].back();
                hashSet[hash].pop_back();
                --size;
                return true;
            }
        }
        return false;
    }

    void rehash(int newCapacity)
    {
        std::vector<std::vector<T>> newHashSet(newCapacity);

        for(int i {}; i < capacity; ++i){
            for (const auto& item : hashSet[i]){ 
                int newHash { std::hash<T>{}(item) % newCapacity };
                newHashSet[newHash].push_back(item);
            }
        }

        hashSet = newHashSet;
        capacity = newCapacity;
    }

    bool exists (const T& item) const 
    {
        int hash { std::hash<T>{}(item) % capacity };
        for (const auto& i : hashSet[hash]){
            if (i == item) return true;
        }

        return false;
    }

    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
    int getCapacity() const { return capacity; }

    void printHashSet() const 
    {
        std::cout << "[\n";
        for (int i{}; i < capacity; ++i){ 
            std::cout << "  [ ";
            for (const auto& item : hashSet[i]){
                std::cout << item << " ";
            }
            std::cout << "]\n";
        }
        std::cout << "]\n";
    }


private:

    static constexpr double loadFactor { 0.75 };
    int capacity { 16 };
    int size {};

    std::vector<std::vector<T>> hashSet;


    //TODO: implement my own hash
    
    bool exists (const T& item, int hash) const
    {
        for (const auto& i : hashSet[hash]){
            if (i == item) return true;
        }

        return false;
    }

};


#endif // HASHSET_H
