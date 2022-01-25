#include "queue.h"

#include <iostream>

int main()
{
    queue<int> q;
    q.push(4);
    q.push(5);
    q.push(2);
    std::cout << q.pop();
    std::cout << q.pop();
    std::cout << q.pop();   
}