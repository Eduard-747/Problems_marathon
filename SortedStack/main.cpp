#include "sorted_stack.h"

#include <iostream>

int main()
{
    sorted_stack<int> s;
    s.push(8);
    s.push(5);
    s.push(2);
    s.push(7);
    while (!s.empty())
    {
        std::cout << s.peek() << " ";
        s.pop();
    }
    
}