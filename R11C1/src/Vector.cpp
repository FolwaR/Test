/*
 * Vector.cpp
 *
 *  Created on: 16 lip 2017
 *      Author: £ukasz
 */

#include "Vector.h"
#include <cmath>


namespace VECTOR
{
const double Rad_to_deg = 45 / atan(1.0);
Vector::Vector()
{
	mode = RECT;
	x = 0.0;
	y = 0.0;
	mag = 0.0;
	ang = 0.0;
}

Vector::Vector(double n1, double n2, Mode form)
{
	if (form == RECT)
	{
		x = n1;
		y = n2;
		mode = form;
		set_mag();
		set_ang();
	}
	else if (form == POL)
	{
		mag = n1;
		ang = n2 / Rad_to_deg;
		mode = form;
		set_x();
		set_y();
	}
	else
	{
		std::cout << "Nieprawidloa wartosc trzeciego argumentu! -- zeruje wektor\n";
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
}

void Vector::reset(double n1, double n2, Mode form)
{
	if (form == RECT)
	{
		x = n1;
		y = n2;
		mode = form;
		set_mag();
		set_ang();
	}
	else if (form == POL)
	{
		mag = n1;
		ang = n2 / Rad_to_deg;
		mode = form;
		set_x();
		set_y();
	}
	else
	{
		std::cout << "Nieprawidloa wartosc trzeciego argumentu! -- zeruje wektor\n";
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
}


Vector::~Vector()
{

}

Vector Vector::operator+(const Vector & v2) const
{
	Vector temp;
	temp.x = x + v2.x;
	temp.y = y + v2.y;

	temp.set_mag();
	temp.set_ang();

	return temp;
}

Vector Vector::operator-(const Vector & v2) const
{
	Vector temp;

	temp.x = x - v2.x;
	temp.y = y - v2.y;

	temp.set_mag();
	temp.set_ang();

	return temp;
}

Vector Vector::operator-() const
{
	Vector temp;

	temp.x = -x;
	temp.y = -y;

	temp.set_mag();
	temp.set_ang();

	return temp;
}

Vector Vector::operator*(const double liczba) const
{
	Vector temp;

	temp.x = x * liczba;
	temp.y = y * liczba;

	temp.set_mag();
	temp.set_ang();

	return temp;
}

Vector operator*(const double n, const Vector v)
{
	return v * n;
}

std::ostream & operator<<(std::ostream & out, const Vector & v)
{
	if (v.mode == Vector::RECT)
		out <<"(x, y) : ("<<v.x <<", "<<v.y<<")";
	else
		out <<"(mag, ang) : ("<<v.mag <<", "<<v.ang<<")";

	return out;
}


void Vector::set_mag()
{
	mag = sqrt(x*x +y*y);
}


void Vector::set_ang()
{
	if (x == 0.0 && y == 0.0)
		ang = 0.0;
	else
		ang = atan2(x,y);
}


void Vector::set_x()
{
	x = mag * cos(ang);
}


void Vector::set_y()
{
	y = mag * sin(ang);
}
}

