#include "studentd.h"

double Student::operator[](int index) const
{
	return ArrayDB::operator[](index);
}

double & Student::operator[](int index)
{
	return ArrayDB::operator[](index);
}


std::ostream & operator<<(std::ostream & out, const Student & stu)
{
	out << (const std::string &) stu;
	stu.dispalyArray(out);
	return out;
}

std::istream & operator>>(std::istream & in , Student & stu)
{
	in >> (std::string &) stu;
	return in;
}

std::istream & getline(std::istream & in, Student & stu)
{
	std::getline(in, (std::string &) stu);
	return in;
}

std::ostream & Student::dispalyArray(std::ostream & out) const
{
	int size = ArrayDB::size();
	
	for (int i = 0; i < size; i++)
		out << ArrayDB::operator[](i)<<" ";

	if (!size)
		out << "Brak lementow tablicy ;/";

	return out;
}


