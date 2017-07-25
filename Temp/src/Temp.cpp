//============================================================================
// Name        : Temp.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


inline int Swap(int &, int &);

template <class type>
auto Swap(type& a, type& b) -> decltype(a+b);

template<>
int Swap(int &, int &);


int main()
{
	int a = 5, b =4;
	cout << "Int a + b = " << function(a, b)<<endl;

	float fa = 5.1, fb =4.5;
	cout << "Int a + b = " << function(fa, fb)<<endl;

	return 0;
}

template <class myType>
auto function(myType a, myType b) -> decltype(a+b)
{
	myType c;

	c = a + b;

	return c;
}
