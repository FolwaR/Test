//============================================================================
// Name        : Pierwszy.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

struct pudlo
{
	char producent[40];
	float wyskosc;
	float szerokosc;
	float dlugosc;
	float objetosc;
};

void display_st_val(const pudlo);
void display_st_ws(const pudlo*);

int main()
{
	pudlo moje_pudlo {"Pudelek",2,2,2,0};

	display_st_val(moje_pudlo);
	cout<<endl;
	display_st_ws(&moje_pudlo);
	cout<<endl;
	return 0;
}


void display_st_val(const pudlo ele)
{
	cout << "Welcome in your first display_st function!"<<endl;
	cout << "Your structure has elements as follows:\n";

	cout <<"Name: "<<ele.producent<<endl;
	cout <<"Height: "<<ele.wyskosc<<endl;
	cout <<"Length: "<<ele.szerokosc<<endl;
	cout <<"Width: "<<ele.dlugosc<<endl;
	cout <<"Volume: "<<ele.objetosc<<endl;

}


void display_st_ws(const pudlo* ele)
{
	cout << "Welcome in your secound display_st function!"<<endl;
	cout << "Your structure has elements as follows:\n";

	cout <<"Name: "<<ele->producent<<endl;
	cout <<"Height: "<<ele->wyskosc<<endl;
	cout <<"Length: "<<ele->szerokosc<<endl;
	cout <<"Width: "<<ele->dlugosc<<endl;
	cout <<"Volume: "<<ele->wyskosc*ele->szerokosc*ele->dlugosc<<endl;

}

