//============================================================================
// Name        : R8C5.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


template <class myType>
myType* maxValue(myType*, int);

template <>
char* maxValue(char* str, int);

const int SIZE = 9;
const int SIZE2 = 4;

int tab[SIZE] = {1,2,3,4,100,6,7,8,9};
double tab2[SIZE] = {1,2,3,4,100.5,6,7,8,9};
float tab3[SIZE] = {1,2,3,4,100.5,6,7,1234,9};

char *tab10[] = {"lol","lolla", "kloala"};

double tab4[SIZE2] = {1.10,101,3,110.1423};
float tab5[SIZE2] = {1.10,101,3,110.1423};;

int main()
{

	maxValue(tab10[0], 2);

	//maxValue(tab, 2);

	return 0;
}


template <class myType>
myType* maxValue(myType *tab, int size)
{
	myType temp;
	for (int i = 0; i < size; i++)
	{
		for(int j = 0; j < size-1; j++)
		{
			if (tab[j+1] > tab[j])
			{
				temp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = temp;
			}
		}
	}

	return tab;
}

template <>
char* maxValue(char* str, int ile)
{
	cout << str+10;
	return str;

}
