/*
 * Osoba.cpp
 *
 *  Created on: 22 lip 2017
 *      Author: £ukasz
 */

#include "Osoba.h"
#include <cstring>
#include <iostream>
Osoba::Osoba()
{
	imie = nullptr;
	nazwisko = nullptr;
	wiek = 0;
}

Osoba::Osoba(const char* imi, const char* naz, int wi)
{
	int temp_len = strlen(imi);
	imie = new char [temp_len+1];
	strncpy(imie, imi, temp_len);

	temp_len = strlen(naz);
	nazwisko = new char [temp_len+1];
	strncpy(nazwisko, naz, wi);

	wiek = wi;
}

void Osoba::i_am()
{
	std::cout <<imie<<" "<<nazwisko<< " "<< wiek<<std::endl;
}


Osoba::~Osoba()
{
	delete [] imie;
	delete [] nazwisko;

}


void Osoba::zrob_kupe()
{
	std::cout << "Robie kup"<<std::endl;
}

void Osoba::zjedz_cos()
{
	std::cout << "Jem cos"<<std::endl;
}

void Osoba::zrob_zakupy()
{
	std::cout << "Robie zakupy"<<std::endl;
}

Polak::Polak(const char* i, const char* n, int w, int k) : Osoba(i,n,w), kredyt(k)
{
}

Polak::~Polak()
{

}

void Polak::ile_kredytu()
{
	std::cout << "Mam: "<<kredyt<<" kredytu ;/"<<std::endl;
}
