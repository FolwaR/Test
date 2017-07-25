/*
 * Brass.cpp
 *
 *  Created on: 22 lip 2017
 *      Author: £ukasz
 */

#include "Brass.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);


Brass::Brass(const std::string & s, long an, double bal ) : fullName(s), accNum(an), balance(bal) {}


Brass::~Brass()
{

}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Nie mozna wplacic ujemnej kworty; "
			 << "Wplata anulowana.\n";
	else
		balance += amt;
}

double Brass::Balance() const
{
	return balance;
}

void Brass::Withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	if (amt < 0)
		cout << "Nie mozna wyplacic ujemnej kworty; "
			 << "Wyplata anulowana.\n";
	else if (amt <= balance)
	{
		balance -= amt;
	}
	else
		cout << "Zadana suma "<<amt
			 << " zl przekracza dostepne srodki.\n"
			 << "Wyplata anulowana.\n";
	restore(initialState, prec);
}

void Brass::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Klient: "<< fullName << endl;
	cout << "Numer rachunku: "<< accNum << endl;
	cout << "Stan konta: " << balance <<endl;
	restore(initialState, prec);
}

format setFormat()
{
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}

BrassGold::BrassGold(const std::string & s, long an, double bal , double ml , double r ) : Brass(s, an, bal), maxLoan(ml),owesBank(0.0), rate(r) {}

BrassGold::BrassGold(Brass & ba,  double ml , double r ) : Brass(ba), maxLoan(ml),owesBank(0.0), rate(r) {}


void BrassGold::Withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = Balance();

	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Zadluzenie faktyczne: "<<advance<<endl;
		cout << "Odsetki: "<<advance*rate<<endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Przekroczyles limit debetu, operacjia anulowana"<<endl;
	restore(initialState, prec);
}

void BrassGold::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();

	cout << "Limit debetu: "<< maxLoan << endl;
	cout << "Kwota zadluzenia: "<< owesBank << endl;
	cout.precision(3);
	cout << "Stopa oprocentoweania: " << 100*rate <<endl;
	restore(initialState, prec);
}





