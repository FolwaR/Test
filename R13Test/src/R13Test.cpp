//============================================================================
// Name        : R13Test.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Osoba.h"

using namespace std;

int main()
{
	Osoba Zbyszek("Zbyszek", "Kowalski",10);
	Zbyszek.i_am();

	Polak Kazik("Kazik", "Nowak", 46, 8000);

	Kazik.i_am();

	Kazik.ile_kredytu();


	Osoba *os;

	os = &Kazik;
	os->i_am();

	os = &Zbyszek;
	os->i_am();

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
