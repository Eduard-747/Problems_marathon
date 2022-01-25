#ifndef STACK_WITH_MIN_H
#define STACK_WITH_MIN_H

#include <iostream>
#include <vector>

template <typename T>
struct node
{
    node * pNext;
    T data;
    node(T data = T() , node * pNext = nullptr) ;
    node(const node&);
};

template <typename T>
class stack_with_min
{
public:
    stack_with_min();
    stack_with_min(const stack_with_min&);
    stack_with_min(stack_with_min&&);
    stack_with_min& operator=(const stack_with_min&);
    stack_with_min& operator=(stack_with_min&&);
    stack_with_min(const std::initializer_list<T>&);
    ~stack_with_min();
public:
    bool empty() const;
    size_t size() const;
    void push(const T&);
    void pop();
    T min() const;
private:
    std::vector<T> mins;
    size_t _size;
    node<T>* top;
};

#include "stack_with_min.hpp"

#endif