/*
 * myString.cpp
 *
 *  Created on: 18 lip 2017
 *      Author: £ukasz
 */

#include "myString.h"
#include <cstring>
namespace MYSTRING {

int myString::ile_obiektow = 0;

myString::myString()
{
	str = nullptr;
	len = 0;
	ile_obiektow++;
}


myString::myString(const char * ch)
{
	len = strlen(ch);
	str = new char [len + 1];
	strcpy(str, ch);
	ile_obiektow++;
}


myString::myString(const myString & mystring)
{
	len = mystring.len;
	str = new char [len + 1];
	strcpy(str, mystring.str);
	ile_obiektow++;
}


myString::~myString()
{
	delete [] str;
	ile_obiektow--;
}


int myString::ile_stringow()
{
	return ile_obiektow;
}


myString & myString::operator=(const myString & mystring)
{
	if (this == &mystring)
		return *this;
	else
	{
		delete [] str;

		len = mystring.len;
		str = new char [len+1];
		strcpy(str, mystring.str);
		return *this;
	}
}


myString & myString::operator=(const char * nstring)
{
	len = strlen(nstring);
	str = new char [len+1];
	strcpy(str, nstring);

	return *this;
}


char & myString::operator[](int index)
{
	return str[index];
}


const char & myString::operator[](int index) const
{
	return str[index];
}


int myString::length() const
{
	return len;
}

const bool myString::operator<(myString & mystring)
{
	if (strcmp(str, mystring.str) < 0)
		return 1;
	else
		return 0;
}


const bool myString::operator>(myString & mystring)
{
	if (strcmp(str, mystring.str) > 0)
		return 1;
	else
		return 0;
}


const bool myString::operator==(myString & mystring)
{
	return !strcmp(str, mystring.str);
}


myString & myString::operator+(myString & mystring)
{
	int new_len = len + mystring.len + 1;

	char *temp = new char [len + 1];

	std::cout <<new_len<<std::endl;

	strcpy(temp, str);

	delete [] str;

	str = new char [new_len] ;
	strncat(str, temp, len);
	strncat(str, mystring.str, new_len);

	std::cout << strlen(str)<<std::endl;

	len = new_len;

	return *this;

}
const myString myString::operator*(double)
{

}

void myString::stringlow(void)
{
	for (int i = 0; i < len; i++)
		if (int(str[i]) > 64 && int(str[i]) < 91)
			str[i] += 32;
}
void myString::stringup(void)
{
	for (int i = 0; i < len; i++)
		if (int(str[i]) > 96 && int(str[i]) < 123)
			str[i] -= 32;
}
int myString::nofchar(void)
{

}



std::ostream & operator<<(std::ostream & out, const myString & mystring)
{
	out << mystring.str;
	return out;
}

std::istream & operator>>(std::istream & in, myString & mystring)
{
	char temp [100];

	in.get(temp,100);

	if (in)
		mystring = temp;
	while (in && in.get() != '\n')
		continue;


	in >> mystring.str;

	return in;
}



} /* namespace MYSTRING */
