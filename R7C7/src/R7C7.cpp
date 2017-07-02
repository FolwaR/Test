//============================================================================
// Name        : R7C7.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

const int MAX = 5;

int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);


int main() {

	double propeties[MAX];

	int size = fill_array(propeties, MAX);
	show_array(propeties, size);

	if (size > 0)
	{
		cout << "Podaj czynnik zmiany wartosci: ";
		double factor;

		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n'){
				//continue;
			}

			cout << "Niepoprawna wartosc, podaj liczbê: ";
		}

		revalue(factor, propeties, size);
		show_array(propeties, size);
	}
	cout << "Gotowe.\n";
	cin.get();
	return 0;
}


int fill_array(double ar[], int limit)
{

}


void show_array(const double ar[], int n)
{

}


void revalue(double r, double ar[], int n)
{

}
