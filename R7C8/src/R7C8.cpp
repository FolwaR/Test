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

const array<string, Seasons> Snames {"Wiosna", "Lato", "Jesien", "Zima"};

void show(array<double, Seasons> ar);
void fill(array<double, Seasons> * ar);

int main()
{
	array<double, Seasons> expenses;

	fill(&expenses);
	show(expenses);

	return 0;
}


void show(array<double, Seasons> ar)
{
	double total = 0.0;

	cout << "\nWydatki\n";

	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] <<": "<<ar[i]<<" zl "<<endl;
		total += ar[i];
	}
	cout <<"Total: "<<total<<endl;
}


void fill(array<double, Seasons> * ar)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Podaj wydatki za okres >>" << Snames[i] << "<<: ";
		cin >> (*ar)[i];
	}

}

