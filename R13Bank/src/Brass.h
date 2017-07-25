/*
 * Brass.h
 *
 *  Created on: 22 lip 2017
 *      Author: £ukasz
 */

#ifndef BRASS_H_
#define BRASS_H_
#include <string>


class Brass
{
private:
	std::string fullName;
	long accNum;
	double balance;
public:
	Brass(const std::string & s = "brak", long an = -1, double bal = 0.0);
	virtual ~Brass();

	void Deposit(double);
	double Balance() const;
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
};

class BrassGold : public Brass
{
private:
	double maxLoan;
	double owesBank;
	double rate;

public:
	BrassGold(const std::string & s = "brak", long an = -1, double bal = 0.0, double ml = 2000, double r = 0.11125);
	BrassGold(Brass & ba,  double ml = 2000, double r = 0.11125);

	virtual void Withdraw(double amt) override;
	virtual void ViewAcct() const override;

	void ResetMax(double m) {maxLoan = m;};
	void ResetRate(double r) {rate = r;};
	void ResetOwes(){owesBank = 0;};
};

#endif /* BRASS_H_ */
