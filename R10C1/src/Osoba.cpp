/*
 * Osoba.cpp
 *
 *  Created on: 12 lip 2017
 *      Author: £ukasz
 */

#include "Osoba.h"

	Osoba::Osoba()
	{

	}

	Osoba::Osoba(const std::string ln, const char * fn)
	{
		lname = ln;
		strncpy(name, fn, LIMIT-1);
		name[LIMIT-1] = '\0';
	}
	void Osoba::show ()const
	{
		std::cout << this->name <<" "<<this->lname;
	}
	void Osoba::FormalShow() const
	{

	}
	Osoba::~Osoba()
	{

	}
