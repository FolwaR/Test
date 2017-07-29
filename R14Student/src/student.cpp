#include "student.h"

double Student::operator[](int index) const
{
	return oceny[index];
}


double & Student::operator[](int index)
{
	return oceny[index];
}


std::ostream & operator<<(std::ostream & out, const Student & stu)
{
	out << stu.name;
	out << "\n";
	stu.displayArray(out);
	return out;
}

std::istream & operator>>(std::istream & in, Student & stu)
{
	std::cout << "Podaj imie studenta: ";
	in >> stu.name;
	return in;
}

std::istream & getline(std::istream & in, Student & stu)
{
	std::getline(in, stu.name);
	return in;
}


std::ostream & Student::displayArray(std::ostream & out) const
{
	int ile = oceny.size();
	
	for (int i = 0; i < ile; i++)
		out << oceny[i] << " ";
	
	if (!ile)
		out << "Tablica jest pusta!";
	
		
	out << std::endl;
	return out;

}







