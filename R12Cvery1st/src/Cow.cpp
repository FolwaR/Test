/*
 * Cow.cpp
 *
 *  Created on: 19 lip 2017
 *      Author: £ukasz
 */

#include "Cow.h"
#include "cstring"

	static int no_of_cows;
	char name[20];
	char * hobby;
	double weight;

Cow::Cow()
{
	name[20] = {'\0'};
	hobby = nullptr;
	weight = 0;
	no_of_cows++;
}


Cow::Cow(const char * na, const char * hbby, double w)
{
	int len = strlen(na);
	hobby = new char [len+1];
	strncpy(hobby, na, len+1);

	strncpy(name, hbby, 20);

	weight = w;
	no_of_cows++;
}


Cow::Cow(Cow & c)
{
	int len = strlen(c.name);

}


Cow & Cow::operator=(Cow &)
{

}


Cow::~Cow()
{
	delete [] hobby;
}


int Cow::get_number_of_cows()
{
	return no_of_cows;
}


