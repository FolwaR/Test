//============================================================================
// Name        : Ile_wystapien_znaku.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : R7C8.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;


char lancych[] = "AAAAAAAAAA";
char znak = 'A';

unsigned int funkcja(char *, char);

int main()
{
	cout << "Wystapien: "<< funkcja(lancych, znak);
	cout << endl;

	return 0;
}


unsigned int funkcja(char * string, char my_char)
{
	unsigned int ile = 0;

	while (*string != '\0')
	{
		if(*string == my_char)
			ile++;

		string++;
	}

	return ile;
}
