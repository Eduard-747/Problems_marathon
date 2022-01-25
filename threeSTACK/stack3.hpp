#include "stack3.h"

template <typename T>
stack3<T>::stack3()
{
    capacity = 1;
    arr.resize(capacity * 3);
}

template <typename T>
stack3<T>::stack3(const stack3& other)
{
    _size1 = other._size1;
    _size2 = other._size2;
    _size3 = other._size3;
    capacity = other.capacity;
    arr = other.arr;
}

template <typename T>
stack3<T>::stack3(stack3&& other)
{
    _size1 = other._size1;
    _size2 = other._size2;
    _size3 = other._size3;
    capacity = other.capacity;
    arr = std::move(other.arr);
}

template <typename T>
stack3<T> & stack3<T>::operator=(const stack3& other)
{
    _size1 = other._size1;
    _size2 = other._size2;
    _size3 = other._size3;
    capacity = other.capacity;
    arr = other.arr;
}

template <typename T>
stack3<T>& stack3<T>::operator=(stack3&& other)
{
    _size1 = other._size1;
    _size2 = other._size2;
    _size3 = other._size3;
    capacity = other.capacity;
    arr = std::move(other.arr);
}

template <typename T>
void stack3<T>::adapt_vec()
{
    for(int i = capacity ; i < capacity + _size3; ++i)
    {
        arr[i + capacity] = arr[i];
    }
    for(int i = capacity / 2; i < capacity / 2 + _size2; ++i)
    {
        arr[i + capacity / 2] = arr[i];
    }
}

template <typename T>
void stack3<T>::push1(const T& val)
{

    if(_size1 == capacity)
    {
        capacity *= 2;
        arr.resize(capacity * 3);
        adapt_vec();
    }
    arr[(capacity * 0)+ _size1] = val;
    ++_size1;
}

template <typename T>
void stack3<T>::push2(const T& val)
{
    if(_size2 == capacity)
    {
        capacity *= 2;
        arr.resize(capacity * 3);
        adapt_vec();
    }
    arr[(capacity * 1)+ _size2] = val;
    ++_size2;
}

template <typename T>
void stack3<T>::push3(const T& val)
{
    if(_size3 == capacity)
    {
        capacity *= 2;
        arr.resize(capacity * 3);
        adapt_vec();
    }
    arr[(capacity * 2)+ _size3] = val;
    ++_size3;
}

template <typename T>
void stack3<T>::pop1()
{
    --_size1;
}

template <typename T>
void stack3<T>::pop2()
{
    --_size2;
}

template <typename T>
void stack3<T>::pop3()
{
    --_size3;
}

template <typename T>
size_t stack3<T>::size_1() const
{
    return _size1;
}

template <typename T>
size_t stack3<T>::size_2() const
{
    return _size2;
}

template <typename T>
size_t stack3<T>::size_3() const
{
    return _size3;
}