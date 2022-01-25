#ifndef STACK3_H
#define STACK3_H

#include <vector>

template <typename T>
class stack3
{
public:
    stack3();
    stack3(const stack3&);
    stack3(stack3&&);
    stack3& operator=(const stack3&);
    stack3& operator=(stack3&&);
public:
    void push1(const T&);
    void push2(const T&);
    void push3(const T&);
    void pop1();
    void pop2();
    void pop3();
    size_t size_1() const;
    size_t size_2() const;
    size_t size_3() const;
private:
    void adapt_vec();
    friend int main();
private:
    size_t _size1{};
    size_t _size2{};
    size_t _size3{};
    size_t capacity;
    std::vector<T> arr;
};

#include "stack3.hpp"

#endif