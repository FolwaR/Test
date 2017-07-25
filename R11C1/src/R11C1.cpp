//============================================================================
// Name        : R11C1.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"
#include <fstream>

int main()
{
	using namespace std;
	using VECTOR::Vector;

	ofstream fout;
	fout.open("marsz.txt", ios::out | ios::app);

	srand(time(0));

	double direction = 0;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target = 0;
	double dstep = 0;

	cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
	while (cin >> target)
	{
		cout << "Podaj dlugosc kroku: ";
		if(!(cin >> dstep))
			break;

		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}

		cout << "Po " << steps <<" krokach delikwent osiagnal polozenie:\n";
		fout << "Po " << steps <<" krokach delikwent osiagnal polozenie:\n";
		cout << result <<endl;

		fout << result <<endl;

		result.polar_mode();

		cout << "czyli\n"<<result<<endl;
		fout << "czyli\n"<<result<<endl;

		cout << "Srednia dlugosc kroku pozornego = "<<result.magval()/steps << endl;
		fout << "Srednia dlugosc kroku pozornego = "<<result.magval()/steps << endl;
		steps = 0;
		result.reset(0.0,0.0);
		cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
		fout << "----------------------------------------------------\n";
	}
	cout << "Koniec!\n";
	fout.close();
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return 0;
}
