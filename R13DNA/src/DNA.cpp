/*
 * DNA.cpp
 *
 *  Created on: 24 lip 2017
 *      Author: £ukasz
 */

#include "DNA.h"
#include <cstring>

baseDNA::baseDNA(const char * l, int r)
{
	label = new char [strlen(l)+1];
	strncpy(label, l, strlen(l)+1);
	rating = r;
}

baseDNA::baseDNA(const baseDNA & bN)
{
	label = new char [strlen(bN.label)+1];
	strncpy(label, bN.label, strlen(bN.label)+1);
	rating = bN.rating;
}


baseDNA & baseDNA::operator=(const baseDNA & bN)
{
	if (this == &bN)
		return *this;

	else{
		delete [] label;

		label = new char [strlen(bN.label)+1];
		strncpy(label, bN.label, strlen(bN.label)+1);
		rating = bN.rating;

		return *this;
	}
}

baseDNA::~baseDNA()
{
	delete [] label;
}


std::ostream & operator<<(std::ostream& out, const baseDNA & bN)
{
	out << "bN.label = " << bN.label <<", bN.rating = " << bN.rating <<std::endl;
	return out;
}


lacksDNA::lacksDNA(const char * c, const char * l , int r ) : baseDNA(l, r)
{
	strncpy(color, c, 39);
	color[39] = '\0';
}

lacksDNA::lacksDNA(const char * c, const baseDNA & bD) : baseDNA(bD)
{
	strncpy(color, c, 39);
	color[39] = '\0';
}

std::ostream & operator<<(std::ostream& out, const lacksDNA & lD)
{
	out << (const baseDNA &) lD << std::endl;
	out <<"lD.color: "<<lD.color<< std::endl;
	return out;
}


hasDNA::hasDNA(const char * s, const char * l, int r ) : baseDNA(l, r)
{
	style = new char [strlen(s)+1];
	strncpy(style, s, strlen(l)+1);
}

hasDNA::hasDNA(const char * s, const baseDNA & bD) : baseDNA(bD)
{
	style = new char [strlen(s)+1];
	strncpy(style, s, strlen(s)+1);
}

hasDNA::hasDNA(const hasDNA & hN) : baseDNA(hN)
{
	style = new char [strlen(hN.style)+1];
	strncpy(style, hN.style, strlen(hN.style)+1);
}

hasDNA::~hasDNA()
{
	delete [] style;
}

hasDNA & hasDNA::operator=(const hasDNA & hN)
{
	if (this == &hN)
		return *this;

	else
	{
		baseDNA::operator=(hN);
		delete [] style;
		style = new char [strlen(hN.style)+1];
		strncpy(style, hN.style, strlen(hN.style)+1);
		return *this;
	}

}

std::ostream & operator<<(std::ostream & out, hasDNA & hD)
{
	out << (const baseDNA &) hD << std::endl;
	out <<"hD.style: "<<hD.style<< std::endl;
	return out;
}






