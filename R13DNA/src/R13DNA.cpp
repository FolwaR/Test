//============================================================================
// Name        : R13DNA.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DNA.h"

using namespace std;

int main()
{
	baseDNA bN("Dupa", 10);
	baseDNA bN2 = bN;
	baseDNA bN3("Dupa2", 10);

	bN3 = bN2;


	cout << bN <<endl;
	cout << bN2 <<endl;
	cout << bN3<<endl;
	return 0;
}
