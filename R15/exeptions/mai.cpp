#include <iostream>
#include <stdlib.h>

using namespace std;

double dzielenie(double a, double b);


int main()
{

    
    double a,b,c;

    cout << "Podaj dwie liczby: ";
    
    while (cin >> a >> b)
    {
        try
        {
            c = dzielenie(a, b);
        }
        catch (const char * s)
        {
            cout << s << endl;
            cout << "POdaj kolejną parę liczb!"<<endl;    
            continue;
        }
        cout << "Wynik operacji dzielenia: " << c << endl;   
    }
    cout << "Poprawne zakończenie programu" << endl;
    return 0;
}


double dzielenie(double a, double b)
{
    if (!b)
        throw "Dzielenie przez ZERO. KURWO";
    else
        return a / b; 
}

