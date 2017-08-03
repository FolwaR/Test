/*
 * DNA.h
 *
 *  Created on: 24 lip 2017
 *      Author: £ukasz
 */

#ifndef BASEDNA_H_
#define BASEDNA_H_
#include <iostream>
class baseDNA
{
	char * label;
	int rating;
public:
	baseDNA(const char * l = "brak", int r = 0);
	baseDNA(const baseDNA &);

	baseDNA & operator=(const baseDNA &);

	friend std::ostream & operator<<(std::ostream&, const baseDNA &);

	virtual ~baseDNA();
};



class lacksDNA : public baseDNA
{
private:
	enum {max=40};
	char color[max];
public:
	lacksDNA(const char * c = "brak", const char * l = "brak", int r = 0);
	lacksDNA(const char * c, const baseDNA & bD);
	friend std::ostream & operator<<(std::ostream&, const lacksDNA &);
};




class hasDNA : public baseDNA
{
private:
	char * style;
public:
	hasDNA(const char * s = "brak", const char * l = "brak", int r = 0);
	hasDNA(const char * s, const baseDNA & bD);
	hasDNA(const hasDNA &);
	virtual ~hasDNA();
	hasDNA & operator=(const hasDNA &);
	friend std::ostream & operator<<(std::ostream &, hasDNA &);

};

#endif /* DNA_H_ */
