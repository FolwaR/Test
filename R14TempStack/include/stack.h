#ifndef _STACK_H_
#define _STACK_H_

template <typename T>
class Stack
{
	private:
		enum {MAX = 10};
		int top;		
		T item[MAX];
	public:
	
		Stack();		

		bool is_full();
		bool is_empty();
		
		bool push(const T &);
		bool pop(T &);	

};

template <typename T>
Statck<T>::Stack()
{
	top = 0;
}


template <typename T>
bool Stack<T>::is_full()
{
	return top == MAX;
}

template <typename T>
bool Stack<T>::is_empty()
{
	return top == 0;
}

template <typename T>
bool Stack<T>::push(const T & it)
{
	if (top < MAX)
	{
		item[top++] = it;
		return true;
	}
	else
		return false;

}






#endif
