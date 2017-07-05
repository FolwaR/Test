//============================================================================
// Name        : R7C9.cpp
// Author      : £ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>

using namespace std;

const int SLEN = 30;

struct Student;


int getInfo(Student *student, int n);

void display3(const Student *, unsigned int n);

void display1(const Student);

void display2(const Student *);

struct Student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};


int main()
{
	Student *students;

	cout << "Podaj liczbe studentow: ";

	int ile_studentow;

	cin >> ile_studentow;
	cin.get();
	students = new Student [ile_studentow];

	int opisanych_studentow;

	//Student lol;

	opisanych_studentow = getInfo(students, ile_studentow);

	cout << endl;
	display1(students[0]);
	cout << endl;
	display2(&students[2]);
	cout << endl;
	display3(students, opisanych_studentow);
	cout << endl;

	return 0;
}

//


int getInfo(Student *student, int n)
{
	int i = 0;
	char temp[SLEN];

	while(i < n)
	{
		cout << "\nPodaj nazwisko studenta "<<i+1<<": ";

		if(!cin.get(temp,SLEN))
			break;

		strcpy(((student+i)->fullname), temp);
		cin.get();

		cout << "Podaj hobby studenta "<<i+1<<": ";
		cin.get(temp,SLEN);
		//cin.clear();
		strcpy(((student+i)->hobby), temp);

		cout << "Podaj ooplevel studenta "<<i+1<<": ";
		cin >> (student+i)->ooplevel;
		cin.get();

		i++;
	}
	cout <<endl;
	return i;
}

void display3(const Student *stud, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
		cout <<"Studen ["<<i+1<<"]. Nazwisko: "<<(stud+i)->fullname<<". Hobby: "<<((stud+i)->hobby)<<". Ooplevel: "<<((stud+i)->ooplevel)<<endl;
}


void display1(const Student stud)
{
	cout <<"Nazwisko: "<<stud.fullname<<". Hobby: "<<(stud.hobby)<<". Ooplevel: "<<(stud.ooplevel)<<endl;
}


void display2(const Student *stud)
{
	cout <<"Nazwisko: "<<stud->fullname<<". Hobby: "<<(stud->hobby)<<". Ooplevel: "<<(stud->ooplevel)<<endl;
}
