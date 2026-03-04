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
    
    T& operator[](int index)
    {
        return data[index];
    }

    void reserve(const int& cap) {}

    void resize(const int& sz) {}

    // TODO: handle initial capacity empty 
    void push_back(const T& item) 
    {
        // == probably fine
        if (size >= capacity) {
            T *newData = new T[2 * capacity];

            for(int i{}; i < capacity; ++i){
                newData[i] = data[i];
            }

            capacity *= 2;
            delete[] data;
            data = newData;
        }
        // post increment because
        // we want to insert at size
        // and then increment
        data[size++] = item;
    }

    // TODO: should destroy the elements not just decriment
    void pop_back() 
    {
        if ( size <= 0 ){
            // maybe make function bool
            return;
        }

        --size;
    }

    //TODO: UB when array is empty
    T back() const { return data[size - 1]; }

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }



    // not sure how to do this
    void for_each() {}

private:

    T *data;
    int size {};
    int capacity { 16 };
};


#endif // DYNAMIC_ARRAY_H
