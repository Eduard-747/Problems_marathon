#include "stack3.h"

#include <iostream>

int main()
{
    stack3<int> s;
    s.push1(2);
    s.push2(5);
    s.push1(12);
    s.push1(99);
    s.push3(8);
    s.pop1();
    s.push1(3);
}