#include <iostream>
#include "exc_mean.h"
#include <cmath>

using namespace std;


double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{
    double x, y, z;
    {
    Demo d1("z bloku zagniezdzonego w funkcji main()\n");
    cout << "Podaj dwie liczby: ";

    while (cin >> x >> y)
    {
        try
        {
            z = means(x, y);
            cout << "Średnia średnich liczb: "<< x << ", " << y <<" jest równa: " << z << endl;
            cout << "Podaj kolejne dwie liczby: ";
        }
        catch (bad_hmean & error)
        {
            cout << "Przechwycono w main()\n";
            error.msgs();
            break;
        }
        catch (bad_gmean & error)
        {
            cout << "Przechwycony w main()\n";
            cout << error.msgs();
            break;
        }
    }
    d1.show();
    }
    cout << "Nieprawidlowe zakończenie programu!" << endl;

    return 0;
}


double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a,b);
    return 2.0 * a*b / (a+b);
}


double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return sqrt(a * b);
}


double means(double a, double b)
{
    double am, hm, gm;
    
    Demo d2("z funkcji mean()");
    am  = (a+b) / 2.0;
    
    try
    {
        hm = hmean(a, b);
        gm = gmean(a, b);
        
    }
    catch (bad_hmean & error)
    {
        cout << "Przechwycone w means()\n";
        error.msgs();
        throw;
    }
    d2.show();
    return (am+hm+gm) / 3.0;
}
