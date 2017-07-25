/*
 * Complex.h
 *
 *  Created on: 17 lip 2017
 *      Author: £ukasz
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>

const double PI = 3.1415;


class Complex {

	private:
		double real;
		double imag;
		double mod;
		double arg;
		enum Mode {Alg, Bieg};
		Complex *tab;
		Mode typ;
		bool tab_jest;

	public:
		Complex(double, double, Mode = Alg);
		Complex(int);
		Complex();
		~Complex();

		double realval() const;
		double imagval() const;
		double modval() const;
		double argval() const;

		void set_real();
		void set_imag();
		void set_mod();
		void set_arg();
		void mode_bieg();
		void mode_alg();


		Complex operator+(const Complex &) const;
		Complex operator-(const Complex &) const;
		Complex operator*(const Complex &) const;

		Complex operator*(double) const;
		Complex operator~() const;

		friend Complex operator*(double d,  Complex & c) {return c * d;};
		friend std::ostream & operator<<(std::ostream & out, const Complex &);
		friend std::istream & operator>>(std::istream & in, Complex &);
		Complex & operator[](int index);


};

#endif /* COMPLEX_H_ */
