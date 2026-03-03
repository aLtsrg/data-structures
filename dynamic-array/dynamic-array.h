#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H


template <typename T>
class DynamicArray
{
public:
    
    // rather than setting capacity could set size
    // then 0 initialize all the memory
    DynamicArray() : data(new T[capacity]) {}
    DynamicArray(int cap) : capacity(cap), data(new T[cap]) {}

    ~DynamicArray() { delete[] data; }

    void reserve(const int& cap) {}

    void resize(const int& sz) {}

    void push_back(const T& item) {}

    void pop_back() {}

    void back() {}

    // not sure how to do this
    void for_each() {}

private:

    T *data;
    int size {};
    int capacity { 16 };
};


#endif // DYNAMIC_ARRAY_H
