/*
 * Cow.h
 *
 *  Created on: 19 lip 2017
 *      Author: £ukasz
 */

#ifndef COW_H_
#define COW_H_

class Cow {

private:
	static int no_of_cows;
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char *, const char *, double);
	Cow(Cow &);
	Cow & operator=(Cow &);
	~Cow();

	static int get_number_of_cows();

};

#endif /* COW_H_ */
