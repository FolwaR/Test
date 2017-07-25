//============================================================================
// Name        : R12C1.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include "myString.h"

using namespace std;

using MYSTRING::myString;

int main()
{
	{

	myString lol("aaaaaaaaaaaaa");
	myString lol2 = "bbbbbbbbbbbbb";

	myString lol3 = "bbbbbbbbbbbbb";
	myString lol4 = lol2;


	cout << lol2<<endl;
			cout	<<lol<<endl;
	cout << lol3 << endl;
	cout << lol4 << endl;
	cout <<myString::ile_stringow()<<endl;

	if(strcmp("aaa","bbb") < 0)
		cout <<"chuj";

	if (lol > lol2)
		cout << "lol wiekszy oid lol2"<<endl;
	if (lol < lol2)
		cout << "lol mniejszy oid lol2"<<endl;

	if (lol3 == lol2)
		cout << "lol rowy oid lol2"<<endl;

	lol.stringlow();
	lol2.stringup();
	cout <<lol<<endl;
	cout <<lol2 <<endl;;


	lol3 = lol + lol2;

	cout << lol3 <<endl;

}



	cout <<myString::ile_stringow()<<endl;


	return 0;
}
