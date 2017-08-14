#include <iostream>
#include <string>

class bad_hmean
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}
    void msgs();
};


void bad_hmean::msgs()
{
    std::cout << "bad_hmean(" << v1 << ", " << v2 << "):" << "niepoprawne argumenty: a = -b/n\n";
}


class bad_gmean
{
private:
    double v1;
    double v2;
public:
    bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
    const char * msgs();
};

const char * bad_gmean::msgs()
{
    return "bad_gmean: powinne być większe od zera!\n";
}


class Demo
{
private:
    std::string word;
public:

    Demo(const char * str)
    {
        word = str;
        std::cout << "Obiekt demo " << word << " utworzony!\n";
    }

    ~Demo()
    {
        std::cout << "Obiekt demo "<< word << " zniszczony!\n";
    }

    void show() const
    {
        std::cout << "Obiekt demo "<< word << " żyje!\n";
    }
};



