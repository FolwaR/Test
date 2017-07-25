/*
 * NumerBankowy.h
 *
 *  Created on: 12 lip 2017
 *      Author: £ukasz
 */

#ifndef NUMERBANKOWY_H_
#define NUMERBANKOWY_H_
#include <cstdlib>
#include <iostream>
#include <cstring>
class NumerBankowy
{
private:
	char surname[40];
	char numer[40];
	double saldo;
public:
	NumerBankowy();
	NumerBankowy(const char* sName, const char* Acc, double sa);
	void show() const;
	bool wplac(int);
	bool wyplac(int);

	~NumerBankowy();
};

#endif /* NUMERBANKOWY_H_ */
