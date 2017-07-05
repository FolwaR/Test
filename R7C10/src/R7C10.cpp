//============================================================================
// Name        : R7C10.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


double add(double, double);
double mul(double, double);
double dif(double, double);
double sub(double, double);

double (*cal[])(double a, double b) = {add,sub,dif,mul};


int main()
{
	double a = 10, b = 5;

	for (int i = 0; i < 4; i++)
		cout << cal[i](a,b) <<endl;

	return 0;
}

double add(double a, double b)
{
	return a+b;
}

double mul(double a, double b)
{
	return a*b;
}

double dif(double a, double b)
{
	return a/b;
}

double sub(double a, double b)
{
	return a-b;
}

