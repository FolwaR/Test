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

double * fill_array(double *ar_pocz, double *ar_koniec);
void show_array(const double *ar, const double *ar_kon);
void revalue(double r, double *ar, double *ar_kon);


int main() {

	double propeties[MAX];

	double *  arr_koniec = fill_array(propeties, (propeties+MAX));

	show_array(propeties, arr_koniec);

	if (propeties != arr_koniec)
	{
		cout << "Podaj czynnik zmiany wartosci: ";
		double factor;

		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n');

			cout << "Niepoprawna wartosc, podaj liczbê: ";
		}

		revalue(factor, propeties, arr_koniec);
		show_array(propeties, arr_koniec);
	}
	cout << "Gotowe.\n";
	cin.get();
	return 0;
}


double * fill_array(double *ar_pocz, double *ar_koniec)
{
	double temp = 0;
	int i = 0;

	while (ar_pocz < ar_koniec)
	{
		cout << "Podaj wartoœæ nr " << (i + 1) << ": ";
		cin >> temp;

		if(!cin)
		{
			cin.clear();

			while (cin.get() != '\n');
				cout << "Wprowadzono bledne dane - koniec programu.\n";

			break;
		}
		else if (temp < 0)
			break;
		*ar_pocz = temp;
		ar_pocz++;
		i++;
	}
	return ar_pocz;
}


void show_array(const double *ar_pocz, const double *ar_kon)
{
	int i = 0;
	while (ar_pocz < ar_kon)
	{
		cout << "Nieruchomoœæ nr " << (i + 1) << ": ";
		cout << *ar_pocz << endl;
		ar_pocz++;
		i++;
	}

}


void revalue(double r, double *ar, double *ar_kon)
{
	while (ar < ar_kon)
	{
		*ar = *ar * r;
		ar++;
	}
}
