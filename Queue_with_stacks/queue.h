#ifndef QUEUE_H
#define QUEUE_H

#include <stack>

template <typename T>
class queue
{
public:
    void push(const T&);
    T pop();
private:
    std::stack<T> s1;
    std::stack<T> s2;
};

#include "queue.hpp"

#endif