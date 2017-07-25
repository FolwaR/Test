/*
 * NumerBankowy.cpp
 *
 *  Created on: 12 lip 2017
 *      Author: £ukasz
 */

#include "NumerBankowy.h"

	NumerBankowy::NumerBankowy()
	{
		strncpy(surname, "Nie podano",39);
		surname[39] = '\0';

		strncpy(numer,  "Nie podano",39);
		numer[39] = '\0';

		saldo = 0;

	}

	NumerBankowy::NumerBankowy(const char * sName, const char * Acc, double sa)
	{
		strncpy(surname, sName,39);
		surname[39] = '\0';

		strncpy(numer, Acc,39);
		numer[39] = '\0';

		saldo = sa;

	}

	void NumerBankowy::show() const
	{
		std::cout <<"Nazwisko: "<< this->surname <<" "<<"\nKonto: "<<this->numer<<" "<<"\nStan konta:" << this->saldo<<std::endl<<std::endl;;

	}
	bool NumerBankowy::wplac(int ile)
	{
		this->saldo += ile;
	}
	bool NumerBankowy::wyplac(int ile)
	{
		if (this->saldo > 0)
		{
			this->saldo -= ile;
		}
	}

	NumerBankowy::~NumerBankowy()
	{

	}
