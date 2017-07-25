//============================================================================
// Name        : R8C7.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


int main()
{
	int n = 10;

	int fib[] = {0,1,1};
	for(int i=2; i<=n; i++)
	{
		fib[i%3] = fib[(i-1)%3] + fib[(i-2)%3];
		cout << "fib(" << i << ") = " << fib[i%3] << endl;
	}
	return fib[n%3];

	return 0;
}

