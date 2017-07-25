/*
 * Osoba.h
 *
 *  Created on: 12 lip 2017
 *      Author: £ukasz
 */

#ifndef OSOBA_H_
#define OSOBA_H_
#include <iostream>
#include <cstring>

class Osoba {
private:
	static const int LIMIT = 256;
	std::string lname;
	char name[LIMIT];

public:
	Osoba();
	Osoba(const std::string ln, const char * fn = "HejTy");
	void show ()const;
	void FormalShow() const;

	~Osoba();
};

#endif /* OSOBA_H_ */
