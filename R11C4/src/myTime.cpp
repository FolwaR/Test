/*
 * myTime.cpp
 *
 *  Created on: 17 lip 2017
 *      Author: £ukasz
 */

#include "myTime.h"

namespace MyTime {


myTime::myTime()
{
	hours = 0;
	miutes = 0;
}
myTime::myTime(int h, int m)
{
	hours = h;
	miutes = m;

	if (miutes > 60)
	{
		hours += miutes / 60;
		miutes = miutes % 60;
	}
}
myTime::~myTime()
{
}

void myTime::AddMin(int m)
{
	miutes += m;
	if (miutes > 60)
	{
		hours += miutes / 60;
		miutes = miutes % 60;
	}
}

void myTime::AddHr(int h)
{
	hours += h;
}

void myTime::Reset(int h, int m)
{
	hours = h;
	miutes = m;
}

myTime operator+(const myTime t1, const myTime t2)
{
	int hu = 0;
	int mi = 0;

	hu = t1.hours + t2.hours;
	mi = t1.miutes + t2.miutes;

	if (mi > 60)
	{
		hu += mi / 60;
		mi = mi % 60;
	}

	return myTime(hu, mi);
}

myTime operator-(const myTime, const myTime)
{
	myTime diff;


}

myTime operator*(const double, const myTime)
{

}

myTime operator*(const myTime, const double)
{

}


std::ostream &  operator<<(std::ostream &, const myTime &)
{

}


} /* namespace MyTime */
