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
		std::strncpy(performers, wyk, 39);
		performers[39] = '\0';

		std::strncpy(label, naz, 19);
		label[19] = '\0';

		selections = sel;
		playtime = tlon;
	}

	Cd::Cd(const Cd & cd)
	{
		std::strncpy(performers, cd.performers, 39);
		performers[39] = '\0';

		std::strncpy(label, cd.label, 19);
		label[19] = '\0';

		selections = cd.selections;
		playtime = cd.playtime;
	}

	Cd::~Cd()
	{

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
			std::strncpy(performers, cd.performers, 39);
			performers[39] = '\0';

			std::strncpy(label, cd.label, 19);
			label[19] = '\0';

			selections = cd.selections;
			playtime = cd.playtime;

			return *this;
		}
	}

	Clasic::Clasic(const char * mT, const char * wyk, const char* naz, int sel, double tlon) : Cd(wyk, naz, sel, tlon)
	{
		std::strncpy(mainTheme, mT, 29);
		mainTheme[29] = '\0';
	}

	Clasic::Clasic(const char * mT, const Cd & cd) : Cd(cd)
	{
		std::strncpy(mainTheme, mT, 29);
		mainTheme[29] = '\0';
	}

	Clasic::Clasic(const Clasic & cl) : Cd(cl)
	{
		std::strncpy(mainTheme, cl.mainTheme, 29);
		mainTheme[29] = '\0';
	}

	Clasic::~Clasic()
	{

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
			std::strncpy(mainTheme, cl.mainTheme, 29);
			mainTheme[29] = '\0';
			return *this;
		}
	}


