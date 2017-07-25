//============================================================================
// Name        : R8C4.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

struct stringy
{
	char * str;
	int ct;
};

void set(stringy& new_str, char *);

void show(stringy&, int = 0);


int main()
{
	stringy testy;
	char testing[] =  "Testowy string";

	set(testy, testing);



	testing[0] = 'D';


	show(testy,5);

	delete [] testy.str;

	return 0;
}


void set(stringy& new_str, char * tekst)
{
	int dlugosc = strlen(tekst);

	new_str.str = new char [dlugosc + 1];

	strcpy(new_str.str, tekst);

	//new_str.str = napis;

	new_str.ct = dlugosc;

	//delete [] napis;
}




void show(stringy& nwe, int new_str)
{
	if (!new_str)
		cout << nwe.str << endl;
	else
		for (int i = 0; i < new_str; i++)
			cout << nwe.str << endl;
}
