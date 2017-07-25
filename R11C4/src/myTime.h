/*
 * myTime.h
 *
 *  Created on: 17 lip 2017
 *      Author: £ukasz
 */

#ifndef MYTIME_H_
#define MYTIME_H_
#include <iostream>
namespace MyTime {

class myTime {

public:

	myTime();
	myTime(int, int = 0);
	~myTime();

	void AddMin(int);
	void AddHr(int);
	void Reset(int = 0, int = 0);

	friend myTime operator+(const myTime, const myTime);
	friend myTime operator-(const myTime, const myTime);
	friend myTime operator*(const double, const myTime);
	friend myTime operator*(const myTime, const double);

	friend std::ostream &  operator<<(std::ostream &, const myTime &);

private:
	int hours;
	int miutes;
};

} /* namespace MyTime */

#endif /* MYTIME_H_ */
