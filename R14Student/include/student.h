#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <valarray>
#include <iostream>

class Student
{
	private:
		typedef std::valarray<double> ArrayDB;
		std::string name;
		ArrayDB oceny;
		std::ostream & displayArray(std::ostream &) const;
	public:
		Student() : name("noName"), oceny(){}
		Student(const char* n, int ile_ocen): name(n), oceny(ile_ocen){}
		explicit Student(const char * n) : name(n), oceny(){}
		explicit Student(int n) : name("noName"), oceny(n){}
		Student(const char * n, const double *tab, int ile_ocen):name(n), oceny(tab, ile_ocen){}
		~Student(){}

		std::string Name();
		
	
		double operator[](int index) const;
		double & operator[](int index);
		friend std::ostream & operator<<(std::ostream & out, const Student &);
		friend std::istream & operator>>(std::istream & in, Student &);
		friend std::istream & getline(std::istream &, Student &);

};




#endif
