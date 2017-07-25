//============================================================================
// Name        : R11C7.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Complex.h"
#include <cmath>

using namespace std;

int main()
{
	Complex a(3.0, 4.0);
	Complex c;

	cout << "Podaj liczbe zespolona"<<endl;;

	cin >> c;


	cout << "c to: "<< c <<endl;
	cout << "Sprzezona z c to: " <<~c<<endl;
	cout << "a to: " <<a<<endl;
	cout << "a + c to: " << a+c <<endl;
	cout << "a - c to: " << a-c <<endl;
	cout << "a * c to: " << a*c <<endl;
	cout << "2 * c to: " << 2*c <<endl;

	return 0;
}
