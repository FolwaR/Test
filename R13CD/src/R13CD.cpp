//============================================================================
// Name        : R13CD.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Cd.h"
using namespace std;

int main()
{
	Cd c1("Bitelsi", "Stolica",14,35.5);
	Clasic c2 = Clasic("Sonata krymska","Szopen", "Sony", 2, 57.14);

	Cd *pcd = &c1;

	cout << "Bezposrednie uzycie obiuekty:\n";
	c1.report();
	c2.report();
	cout << endl;
	cout << "Uzycie wskaznika na typ Cd:\n";
	pcd->report();
	pcd=&c2;
	pcd->report();
	cout << endl;


	cout << "Test przypisania:\n";
	Clasic copy;
	copy = c2;
	copy.report();

	return 0;

}
