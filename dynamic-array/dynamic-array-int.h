#ifndef DYNAMIC_ARR_INT_H 
#define DYNAMIC_ARR_INT_H 

#include <cstddef>

// TODO: add copy constructor and copy assignment
// right now if you use that, it may cause a double delete which is UB

class DynamicArrInt
{
public:
    DynamicArrInt() : data { new int[capacity_] }{}

    ~DynamicArrInt() { delete [] data; }

    //return type is a reference because otherwise it creates a copy and the user can not edit the values in the array
    int& operator[](const size_t& index){
        return data[index];
    }

    void push_back(const int& item)
    {
        if (size_ == capacity_){
            reAllocate();
        }

        data[size_++] = item;
    }

    //no destructor needed because int does not have one
    void pop_back()
    {
        --size_;
    }

    void reserve(const size_t& capacity)
    {
        if (capacity <= capacity_) return;

        while (capacity_ < capacity){
            reAllocate();
        }
    }

    void resize(const size_t& size)
    {
        if (size > size_){
            if (capacity_ < size) reserve(size);

            for (size_t i{size_}; i < size; ++i){
                data[i] = 0;
            }
        }

        size_ = size;
    }

    size_t size() const { return size_; }

    size_t capacity() const { return capacity_; }

    int back() const { return data[size_ - 1]; }


private:

    size_t capacity_ { 256 };
    size_t size_ {};
    int *data;

    void reAllocate()
    {
        //redundant without a constructor that makes this possible
        //TODO: add a constructor or delete
        if (capacity_ == 0){
            capacity_ = 256;
            data = new int[capacity_]; 
            return;
        }

        int *newData { new int[ 2 * capacity_ ] };

        for (size_t i {}; i < size_; ++i){
            newData[i] = data[i];
        }
        
        delete [] data;

        capacity_ *= 2;
        data = newData;
    }
};
#endif // DYNAMIC_ARR_INT
