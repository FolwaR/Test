#ifndef _STACK_H_
#define _STACK_H_


template <class T>

class Stack
{
	private:
		enum {SIZE = 10};
		int stacksize;
		T * item;
		int top;
	public:
		explicit Stack(int ss = SIZE);
		Stack(const Stack & st);
		~Stack() { delete [] T};
		
		bool isempty() { return top == 0;}
		bool isfull() { return top == SIZE;
		bool push(const T &);
		bool pop(T &);
		Stack & operator=(Stack &);
		
};


template <class T>
Stack<T>::Stack(const Stack & st)
{
	stacksize = st.stacksize;
	top = st.top;
	item = new T [stacksize];

	for (int i = 0; i < stacksize; i++)
		item [i] = st.item[i];
}


template <class T>
Stack<T>::Stack(int ss = SIZE)
{
	stacksize = SIZE;
	top = 0;
	
	item = new T [stacksize];
}


template <class T>
bool Stack<T>::push(const T & it) 
{
	if (top < stackszie)
	{
		item[top++] = it;
		return true;
	}
	else
		return false;
}


template <class T>
bool Stack<T>::pop(const T & it)
{
	if (top > 0)
	{
		item = item[--top];
		return true;	
	}
	else
		return false;
}


template <class T>
Stack & Stack<T>::operator=(Stack & st)
{
	if (this == &st)
		return *this;
	
	delete [] T;

	stacksize = st.stacksize;
    top = st.top;
    item = new T [stacksize];

    for (int i = 0; i < stacksize; i++)
        item [i] = st.item[i];
	
	return *this; 
}










#endif
