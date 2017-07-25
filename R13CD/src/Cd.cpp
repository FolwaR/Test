/*
 * Cd.cpp
 *
 *  Created on: 25 lip 2017
 *      Author: £ukasz
 */

#include "Cd.h"
#include <cstring>
#include <iostream>
	Cd::Cd(const char * wyk, const char* naz, int sel, double tlon)
	{
		int len = strlen(wyk);
		performers = new char [len+1];
		std::strcpy(performers, wyk);

		len = strlen(naz);
		label = new char [len+1];
		std::strcpy(label, naz);

		selections = sel;
		playtime = tlon;
	}

	Cd::Cd(const Cd & cd)
	{
		int len = strlen(cd.performers);
		performers = new char [len+1];
		std::strcpy(performers, cd.performers);

		len = strlen(cd.label);
		label = new char [len+1];
		std::strcpy(label, cd.label);

		selections = cd.selections;
		playtime = cd.playtime;
	}

	Cd::~Cd()
	{
		std::cout <<"DUPA w CD"<<std::endl;
		delete [] performers;
		delete [] label;
	}

	void Cd::report()
	{
		std::cout << "Performer: "<<performers<<", label: "<<label<<std::endl;
		std::cout << "Selections: "<<selections<<", time long: "<<playtime<<std::endl;
	}

	Cd & Cd::operator=(const Cd& cd)
	{
		if (this == &cd)
			return *this;
		else
		{
			int len = strlen(cd.performers);
			performers = new char [len+1];
			std::strcpy(performers, cd.performers);

			len = strlen(cd.label);
			label = new char [len+1];
			std::strcpy(label, cd.label);

			selections = cd.selections;
			playtime = cd.playtime;

			return *this;
		}
	}

	Clasic::Clasic(const char * mT, const char * wyk, const char* naz, int sel, double tlon) : Cd(wyk, naz, sel, tlon)
	{
		int len = strlen(mT);
		mainTheme = new char [len+1];
		std::strcpy(mainTheme, mT);
	}

	Clasic::Clasic(const char * mT, const Cd & cd) : Cd(cd)
	{
		int len = strlen(mT);
		mainTheme = new char [len+1];
		std::strcpy(mainTheme, mT);
	}

	Clasic::Clasic(const Clasic & cl) : Cd(cl)
	{
		int len = strlen(cl.mainTheme);
		mainTheme = new char [len+1];
		std::strcpy(mainTheme, cl.mainTheme);
	}

	Clasic::~Clasic()
	{
		std::cout <<"DUPA w Clasic"<<std::endl;
		delete [] mainTheme;
	}

	void Clasic::report()
	{
		Cd::report();
		std::cout << "mainTheme: "<<mainTheme << std::endl;
	}

	Clasic & Clasic::operator=(const Clasic& cl)
	{
		if (this == &cl)
			return *this;
		else
		{
			Cd::operator=(cl);
			int len = strlen(cl.mainTheme);
			mainTheme = new char [len+1];
			std::strcpy(mainTheme, cl.mainTheme);
			return *this;
		}
	}


