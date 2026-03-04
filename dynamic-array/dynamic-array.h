#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef>

template <typename T>
class DynamicArray
{
public:
    
    // rather than setting cap could set size
    // then 0 initialize all the memory
    DynamicArray() : data(new T[cap]) {}
    DynamicArray(int cap) : cap(cap), data(new T[cap]) {}

    ~DynamicArray() { delete[] data; }
    
    T& operator[](int index)
    {
        return data[index];
    }

    void reserve(const int& capacity) {}

    void resize(const int& size) 
    {
        if (size < sz){
            for (size_t i {sz}; i < sz; ++i){
                data[i].~T();
            }
        } else if (size > sz){
            // TODO: implement case where size > sz
        }


        sz = size;
    }

    void push_back(const T& item) 
    {
        // == probably fine
        if (sz >= cap) {
            
            // handle initial empty capacity
            if (cap == 0){
                cap = 16;
                data = new T[cap];
            }

            T *newData = new T[2 * cap];

            for(size_t i{}; i < cap; ++i){
                newData[i] = data[i];
            }

            cap *= 2;
            delete[] data;
            data = newData;
        }
        // post increment because
        // we want to insert at sz
        // and then increment
        data[sz++] = item;
    }

    void pop_back() 
    {
        // call destructor for the back object
        // if there is no destructor eg. T = int, this will be a no-op
        data[sz - 1].~T();
        --sz;
    }

    // UB if call back when sz == 0
    T back() const { return data[sz - 1]; }

    size_t size() const { return sz; }
    size_t capacity() const { return cap; }



    // not sure how to do this
    void for_each() {}

private:

    T *data;
    size_t sz {};
    size_t cap{ 16 };

};

#endif // DYNAMIC_ARRAY_H
