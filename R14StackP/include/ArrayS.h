#ifndef _ARRAYS_H_
#define _ARRAYS_H_

template <class t, int n>
class Array
{
private:
	T ar[n];
public:
	Array(){};
	explicit Array(const Array & v);
	T & operator[](int index);
	T operator[](int index) const;

};

template <class t, int n>



#endif

