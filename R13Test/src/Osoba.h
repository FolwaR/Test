/*
 * Osoba.h
 *
 *  Created on: 22 lip 2017
 *      Author: £ukasz
 */

#ifndef OSOBA_H_
#define OSOBA_H_

class Osoba
{
private:
	char *imie;
	char *nazwisko;
	int wiek;
public:
	Osoba();
	Osoba(const char*, const char*, int);
	~Osoba();

	void zrob_kupe();
	void zjedz_cos();
	void zrob_zakupy();
	void i_am();
};

class Polak : public Osoba
{
private:
	int kredyt;
public:
	Polak(const char*, const char*, int, int);
	~Polak();
	void ile_kredytu();
};




#endif /* OSOBA_H_ */
