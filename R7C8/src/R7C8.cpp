//============================================================================
// Name        : R7C8.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
#include <string>

using namespace std;

const int Seasons = 4;

const char * pory_roku[] = {"Wiosna", "Lato", "Jesien", "Zima"};

void show(double *ar);
void fill(double *ar);

int main()
{
	double expenses[Seasons];

	fill(expenses);
	show(expenses);

	return 0;
}


void show(double *ar)
{
	double total = 0.0;

	cout << "\nWydatki\n";

	for (int i = 0; i < Seasons; i++)
	{
		cout << pory_roku[i] <<": "<<ar[i]<<" zl "<<endl;
		total += ar[i];
	}
	cout <<"Total: "<<total<<endl;
}


void fill(double *ar)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Podaj wydatki za okres >>" << pory_roku[i] << "<<: ";
		cin >> ar[i];
	}

}

