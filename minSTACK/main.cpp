#include "stack_with_min.h"

int main()
{
    stack_with_min<int> s;
    s.push(5);
    s.push(8);
    s.push(9);
    s.push(3);
    std::cout << s.min() << std::endl;
    s.pop();
    std::cout << s.min() << std::endl;
}