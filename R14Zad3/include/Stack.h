#ifndef _STACK_H_
#define _STACK_H_

#include <iostram>


template <typename T>
class Stack
{
    private:
    enum {stack_size = 10};
    T * item;
    int HEAD;    

    public:
    Stack() : item(nullptr), HEAD(0);
    Stack(Stack & s);
    ~Stack();
    //explicit Stack(T &);

    bool isFull();
    bool isEmpty();
    bool pop(const T &);
    bool push(const T &);

    Stack & operator=(const Stack &);
    friend std::ostream operator<<(ostram &, const Stack &);    
    
};


template <typename T>
Stack<T>::Stack(Stack & s)
{
    item = new T [s.stack_size];
    HEAD = s.HEAD;

    for (int i = 0; i < s.HEAD; i++)
        item[i] = s.item[i];

}


template <typename T>
Stack<T>::~Stack()
{
    delete [] item;
}


template <typename T>
bool Stack<T>::isFull()
{
    return HEAD == stack_size;
}


template <typename T>
Stack<T>::isEmpty()
{
    return HEAD == 0;
}


template <typename T>
bool Stack<T>::push(const T & it)
{
    if (!isFull())
    {
        iteam[HAED++] = it;
        return 0
    }
    else
        return 1;
}


template <typename T>
bool Stack<T>::pop(const T & item)
{
    if (!isEmpty())
    {
        item = item[--HEAD];
        return 0;
    }
    else
        return 1;    

}


template <typename T>
Stack & Stack<T>::operator=(const Stack & s) 
{
    if (this = &s)
        return *this;

    delete [] item;

    item = new T [s.stack_size];
    HEAD = s.HEAD;

    for (int i = 0; i < s.HEAD; i++)
        item[i] = s.item[i];

    return 0;
}





#endif    
