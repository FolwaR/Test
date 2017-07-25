//============================================================================
// Name        : R9C1.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Batonik;
void funkcja(const char *, const unsigned int param = 0);
char *stringe = (char*) "Dupa";


void funkcja_fill_Batonik(Batonik *baton, char * name = (char*)"Milenium Match", float masa = 2.85, int kcla = 350);
void funkcja_show_Batonik(const Batonik *);

void upper(string&);





struct Batonik
{
	char *name;
	float masa;
	int klca;
};

int main()
{
	funkcja(stringe);
	funkcja(stringe,10);
	funkcja(stringe,1);
	funkcja(stringe);
	funkcja(stringe);
	funkcja(stringe,1010);

	Batonik mars;

	funkcja_fill_Batonik(&mars);
	funkcja_show_Batonik(&mars);
	funkcja_fill_Batonik(&mars,(char*) "Mars", 1.2,200);
	funkcja_show_Batonik(&mars);

	//string lol = upper("chuj");


	string napis;
	while ((napis = cin.get()) != "q")
	{
		upper(napis);
		cout << napis;
	}

	return 0;
}

void upper(string& napis)
{
	int i = 0;
	while(napis[i] != '\0')
	{
		if (((int)napis[i] > 96) && ((int)napis[i] < 123))
		    napis[i] -= 32;
		i++;
	}
}


void funkcja(const char *my_string, const unsigned int param)
{
	static int ile = 0;
	ile++;

	if (param)
	{
		for (int i = 0; i < ile; i++)
			cout << my_string << " ";
	}
	else
		cout << my_string;

	cout << endl;


}


void funkcja_fill_Batonik(Batonik *baton, char * name, float masa, int kcla )
{
	baton->name = name;
	baton->masa = masa;
	baton->klca = kcla;

}


void funkcja_show_Batonik(const Batonik *baton)
{
	cout << "Nazwa batona: " << baton->name << endl;
	cout << "Masa batona: " << baton->masa << endl;
	cout << "Kcla batona: " << baton->klca << endl;
}
