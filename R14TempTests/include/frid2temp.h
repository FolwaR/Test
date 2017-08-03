#ifndef _HAS_FRIEND_H_
#define _HAS_FRIEND_H_


template <typename T>
class HasFriend
{

	private:
	
	T item;
	static int c;


	public:

	HasFriend(const T& t) : item(t) { c++ ;}	
	~HasFriend() { c-- ;}

	friend void count();
	friend void report(HasFriend<T> & t); 

};


template <typename T>
int HasFriend<T>::c = 0;

void count()
{
	cout << "Konkretyzacje int: " << HasFriend<int>::c <<"; ";
	cout << "Konkretyzacje double " << HasFriend<double>::c << "; ";
}


void report(HasFriend<int> & t)
{
	cout << "HasFriend<int>: " << t.c << endl;
}

void report(HasFriend<double> & t)
{
	cout << "HasFriend<double>: " << t.c << endl; 
}





#endif


