/*
 * myString.h
 *
 *  Created on: 18 lip 2017
 *      Author: £ukasz
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>

namespace MYSTRING {

class myString
{
	static int ile_obiektow;
	char * str;
	int len;
public:
	myString();
	myString(const char *);
	myString(const myString &);

	static int ile_stringow();

	myString & operator=(const myString &);
	myString & operator=(const char *);
	char & operator[](int);
	const char & operator[](int) const;

	int length() const;

	const bool operator<(myString &);
	const bool operator>(myString &);
	const bool operator==(myString &);
	myString & operator+(myString &);
	const myString operator*(double);

	void stringlow(void);
	void stringup(void);
	int nofchar(void);



	friend std::ostream & operator<<(std::ostream &, const myString &);
	friend std::istream & operator>>(std::istream &, myString &);
	friend myString operator*(double n, myString & s) {return s * n;};

	~myString();
};

} /* namespace MYSTRING */

#endif /* MYSTRING_H_ */
