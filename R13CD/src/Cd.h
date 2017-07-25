/*
 * Cd.h
 *
 *  Created on: 25 lip 2017
 *      Author: £ukasz
 */

#ifndef CD_H_
#define CD_H_

class Cd
{
private:
	char * performers;
	char * label;
	int selections;
	double playtime;

public:
	Cd(const char * = "noName", const char* = "noName", int = 0, double = 0);
	Cd(const Cd &);

	virtual ~Cd();
	virtual void report();
	Cd & operator=(const Cd&);

};

class Clasic : public Cd
{
private:
	char * mainTheme;
public:
	Clasic(const char * = "noName", const char * = "noName", const char* = "noName", int = 0, double = 0);
	Clasic(const char *, const Cd &);
	Clasic(const Clasic &);
	virtual ~Clasic();
	virtual void report();
	Clasic & operator=(const Clasic&);
};


#endif /* CD_H_ */
