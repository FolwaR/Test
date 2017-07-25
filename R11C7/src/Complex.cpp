/*
 * Complex.cpp
 *
 *  Created on: 17 lip 2017
 *      Author: £ukasz
 */

#include "Complex.h"
#include <cmath>

Complex::Complex(double r, double i, Mode m)
{
	typ = m;
	tab = NULL;
	tab_jest = false;

	if (typ == Alg)
	{
		real = r;
		imag = i;
		set_mod();
		set_arg();
	}
	else if (typ == Bieg)
	{
		mod = r;
		arg = i * PI/180;
		set_real();
		set_arg();
	}

}

Complex::Complex(int N)
{
	tab = new Complex [N];
	for (int i = 0; i < N; i++)
	{
		tab[i] = Complex();
	}
	tab_jest = true;
}

Complex::Complex()
{
	real = 0;
	imag = 0;
	typ = Alg;
	tab = NULL;
	tab_jest = false;
	set_mod();
	set_arg();
}


Complex::~Complex()
{
	if (tab_jest)
		delete [] tab;
}


double Complex::realval() const
{
	return real;
}
double Complex::imagval() const
{
	return imag;
}
double Complex::modval() const
{
	return mod;
}
double Complex::argval() const
{
	return arg;
}


void Complex::set_real()
{
	real = mod * cos(arg);
}


void Complex::set_imag()
{
	imag = mod * sin(arg);
}


void Complex::set_mod()
{
	mod = sqrt(real*real + imag*imag);
}


void Complex::set_arg()
{
	if (real == 0.0 && imag == 0.0)
		arg = 0.0;
	else
		arg = atan2(imag, real);
}


Complex Complex::operator+(const Complex & c2) const
{
	double n_real = 0;
	double n_imag = 0;

	n_real = real + c2.real;
	n_imag = imag + c2.imag;

	return Complex(n_real, n_imag);
}


Complex Complex::operator-(const Complex & c2) const
{
	double n_real = 0;
	double n_imag = 0;

	n_real = real - c2.real;
	n_imag = imag - c2.imag;

	return Complex(n_real, n_imag);
}


Complex Complex::operator*(const Complex & c2) const
{
	double n_real = 0;
	double n_imag = 0;

	n_real = (real*c2.real) - (imag*c2.imag);
	n_imag = (real*c2.imag) + (imag*c2.real);

	return Complex(n_real, n_imag);
}


Complex Complex::operator*(double x) const
{
	double n_real = 0;
	double n_imag = 0;

	n_real = x * real;
	n_imag = x * imag;

	return Complex(n_real, n_imag);
}


Complex Complex::operator~() const
{
	return Complex(real, -imag);
}


Complex & Complex::operator[](int index)
{
	return tab[index];
}

void Complex::mode_bieg()
{
	typ = Complex::Bieg;
}

void Complex::mode_alg()
{
	typ = Complex::Alg;
}

std::ostream & operator<<(std::ostream & out, const Complex & c)
{
	if (c.typ == Complex::Alg)
	{
		if (c.imag > 0)
			out << c.real << "+j" <<c.imag;
		else
			out << c.real << "-j" <<-c.imag;
	}
	else if (c.typ == Complex::Bieg)
	{
		out << c.mod<< "e^"<<c.arg*180/PI;
	}

	return out;
}

std::istream & operator>>(std::istream & in, Complex & c)
{
	std::cout << "Podaj czesc rzeczywista: ";
	in >> c.real;
	std::cout << "Podaj czesc urojona: ";
	in >> c.imag;
	c.set_mod();
	c.set_arg();
	return in;
}
