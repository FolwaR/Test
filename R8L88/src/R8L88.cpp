//============================================================================
// Name        : R8L88.cpp
// Author      : �ukasz Folwarczyk
// Version     :
// Copyright   : Spierdalaj
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;
const int LIMIT = 5;
void file_it(ostream & os, double fo, const double fe[],int n);

int main()
{
	ofstream fout;
	const char * fn = "ep-data.txt";

	fout.open(fn);

    if (!fout.is_open())
    {
        cout << "Nie mog� otworzy� " << fn << ". Do widzenia.\n";
        exit(EXIT_FAILURE);
    }

    double objective;

    cout << "Podaj ogniskow� teleskopu w milimetrach:";

    cin >> objective;

    double eps[LIMIT];

    cout << "Podaj ogniskowe (w mm) " << LIMIT << " okular�w:\n";

    for (int i = 0; i < LIMIT; i++)
    {
    	cout << "Okular nr " << i + 1 << ": ";
    	cin >> eps[i];
    }

    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);
    cout << "Gotowe\n";
    return 0;

	return 0;
}

void file_it(ostream & os, double fo, const double fe[],int n)
{
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); // zachowaj formatowanie pocz�tkowe
    os.precision(0);
    os << "Ogniskowa obiektywu: " << fo << " mm\n";
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "f okularu";
    os.width(15);
    os << "powi�kszenie" << endl;
    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int (fo/fe[i] + 0.5) << endl;
    }
    os.setf(initial);   // przywr�cenie pocz�tkowych ustawie� formatowania
}
