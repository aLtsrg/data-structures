#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef>

template <typename T>
class DynamicArray
{
public:
    
    //operator new returns void*
    DynamicArray() : data{ static_cast<T*>(operator new(capacity_ * sizeof(T))) } {}
    DynamicArray(size_t capacity) : capacity_{capacity}, data{ static_cast<T*>(operator new(capacity_ * sizeof(T))) } {}

    ~DynamicArray() 
    { 
        for (size_t i {}; i < size_; ++i){
            data[i].~T();
        }

        //operator delete expects void*
        operator delete(static_cast<void*>(data)); 
    }
    
    T& operator[](size_t index)
    {
        return data[index];
    }

    void reserve(const size_t& capacity) 
    {
        //cannot shrink
        if (capacity <= capacity_) return;

        while (capacity_ < capacity){
            reAllocate();
        }
    }

    void resize(const size_t& size) 
    {
        if (size == size_) return;
        
        //resize to size smaller than current size
        if (size < size_){
            for (size_t i {size}; i < size_; ++i){
                data[i].~T();
            }
        //resize to larger size
        } else {
            if (size > capacity_) reserve(size);

            for (size_t i {size_}; i < size; ++i){
                
                //placement new, see: https://en.cppreference.com/w/cpp/language/new.html
                //default allocates T at specified memory location
                new (data + i) T;
            }
        }

        size_ = size;
    }

    void push_back(const T& item) 
    {
        if (size_ == capacity_) {
            reAllocate();    
        }
        // post increment because
        // we want to insert at size_
        // and then increment
        new (data + size_) T(item);
        ++size_;
    }

    void pop_back() 
    {
        // call destructor for the back object
        // only neccsary because of template type
        // if there is no destructor eg. T = int, this will be a no-op
        data[size_ - 1].~T();
        --size_;
    }

    // UB if call back when sz == 0
    T back() const { return data[size_ - 1]; }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }



    // not sure how to do this
    void for_each() {}

private:

    size_t capacity_ { 256 };
    size_t size_ {};
    T *data;

    void reAllocate()
    {
        // handle initial empty capacity
        if (capacity_ == 0){
            capacity_ = 256;
            
            data = static_cast<T*>(operator new(capacity_ * sizeof(T)));
            return;
        }

        T *newData = static_cast<T*>(operator new(2 * capacity_ * sizeof(T)));

        for(size_t i{}; i < size_; ++i){
            new (newData + i) T(data[i]);
            data[i].~T();
        }

        capacity_ *= 2;
        operator delete(static_cast<void*>(data));
        data = newData;
    }

};

#endif // DYNAMIC_ARRAY_H
