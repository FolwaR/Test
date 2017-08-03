#include <iostream>
#include <valarray>

class Student : private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDB;
	std::ostream & dispalyArray(std::ostream &) const;

public:
	Student() : std::string("noName"), ArrayDB() {}
	Student(const std::string n, int no) : std::string(n), ArrayDB(no) {}
	explicit Student(const std::string n) : std::string(n), ArrayDB() {}
	explicit Student(int n) : std::string(), ArrayDB(n) {}
	Student(const std::string n, const double * tab, int no) : std::string(n), ArrayDB(tab, no) {}
	~Student() {};


	double operator[](int index) const;
	double & operator[](int index);

	friend std::ostream & operator<<(std::ostream & out, const Student & stu);
	friend std::istream & operator>>(std::istream & in , Student & stu);
	friend std::istream & getline(std::istream & in, Student & stu);


};
