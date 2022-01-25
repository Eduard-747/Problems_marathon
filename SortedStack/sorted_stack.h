#ifndef SORTED_STACK_H
#define SORTED_STACK_H

#include <stack>

template <typename T>
class sorted_stack
{
public:
    void push(const T&);
    void pop();
    T peek() const;
    bool empty() const;
    size_t size() const;
private:
    std::stack<T> s;
};

#include "sorted_stack.hpp"

#endif