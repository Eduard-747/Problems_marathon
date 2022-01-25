template <typename T>
void queue<T>::push(const T& elem)
{
    s1.push(elem);
}

template <typename T>
T queue<T>::pop()
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    T tmp = s2.top();
    s2.pop();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return tmp;
}
