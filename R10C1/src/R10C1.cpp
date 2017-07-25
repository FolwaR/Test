//============================================================================
// Name        : R10C1.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "NumerBankowy.h"
#include "Osoba.h"
using namespace std;

int main()
{
	NumerBankowy Janek;
	NumerBankowy Janek2 {"Nowak", "12345678910213", 10};

	Osoba nikt {"Chuj", "Chujdf"};


	Janek.show();
	Janek2.show();

	Janek.wplac(100);
	Janek.show();

	nikt.show();

	return 0;
}
