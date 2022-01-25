template <typename T>
void sorted_stack<T>::push(const T& elem)
{
    if (s.empty())
	{
		s.push(elem);
	}
	else if (elem < s.top())
	{
		s.push(elem);
	}
	else
	{
		std::stack<T> tmp;
		while ((!s.empty()) && (elem >= s.top()))
		{
			tmp.push(s.top());
			s.pop();
		}
		tmp.push(elem);
		while (!tmp.empty())
		{
			s.push(tmp.top());
			tmp.pop();
		}
	}

}

template <typename T>
void sorted_stack<T>::pop()
{
    s.pop();
}

template <typename T>
T sorted_stack<T>::peek() const
{
    return s.top();
}

template <typename T>
bool sorted_stack<T>::empty() const
{
    return s.empty();
}

template <typename T>
size_t sorted_stack<T>::size() const
{
    return s.size();
}