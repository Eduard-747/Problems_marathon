template <typename T>
node<T>::node(T data, node * pNext)
{
    this->data = data;
    this->pNext = pNext;
}

template <typename T>
node<T>::node(const node<T>& other)
{
    data = other.data;
    pNext = other.pNext;
}

template <typename T>
stack_with_min<T>::stack_with_min()
{
    _size = 0;
    top = nullptr;
}

template <typename T>
stack_with_min<T>::stack_with_min(const stack_with_min<T>& other)
{
    if (other.top == nullptr) {
        top = nullptr;
    }
    else {
        top = new node<T>(other.top->data);
        node<T> *current = top;
        node<T> *objtop = other.top;
        node<T> *currentObj = objtop;
        while (currentObj->pNext != nullptr) 
        {
            current->pNext = new node<T>(currentObj->pNext->data);
            currentObj = currentObj->pNext;
            current = current->pNext;
        }
    }
}

template <typename T>
stack_with_min<T>::stack_with_min(stack_with_min<T>&& other)
{
    _size = other._size;
    top = other.top;
    other.top = nullptr;
}

template<typename T>
stack_with_min<T>::stack_with_min(const std::initializer_list<T>& elems) {
    _size = elems.size() ;
    top = nullptr;
    for(auto it = elems.begin() ; it != elems.end(); ++it) 
    {
        top = new node<T>(*it,top);
    }
}


template <typename T>
stack_with_min<T>& stack_with_min<T>::operator=(const stack_with_min<T>& other)
{
    if (other.top == nullptr) {
        top = nullptr;
    }
    else {
        while (top)
        {
            node<T> * tmp = top;
            top = top->pNext;
            delete tmp;
        }
        top = new node<T>(other.top->data);
        node<T> *current = top;
        node<T> *objtop = other.top;
        node<T> *currentObj = objtop;
        while (currentObj->pNext != nullptr) 
        {
            current->pNext = new node<T>(currentObj->pNext->data);
            currentObj = currentObj->pNext;
            current = current->pNext;
        }
    }
    return *this;
}

template <typename T>
stack_with_min<T>& stack_with_min<T>::operator=(stack_with_min<T>&& other)
{
    while (top)
    {
        node<T> * tmp = top;
        top = top->pNext;
        delete tmp;
    }
    top = other.top;
    other.top = nullptr;
    return *this;
}

template <typename T>
void stack_with_min<T>::push(const T& elem)
{
    if(mins.empty())
    {
        mins.push_back(elem);
    } else if(elem < *(mins.end() - 1)) {
        mins.push_back(elem);
    }
    top = new node<T>(elem, top);
    ++_size;
}

template <typename T>
void stack_with_min<T>::pop()
{
    node<T> *tmp = top;
    if(tmp->data == *(mins.end() - 1))
    {
        mins.pop_back();
    }
    top = top->pNext;
    --_size;
    delete tmp;
}

template <typename T>
T stack_with_min<T>::min() const
{
    return *(mins.end() - 1);
}

template <typename T>
size_t stack_with_min<T>::size() const
{
    return _size;
}

template <typename T>
bool stack_with_min<T>::empty() const
{
    return top == nullptr? true: false;
}

template <typename T>
stack_with_min<T>::~stack_with_min()
{
    while (top)
    {
        node<T> * tmp = top;
        top = top->pNext;
        delete tmp;
    }
}
