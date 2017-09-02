#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Planet
{
    char name[20];
    double population;
    double g;
};

const char * file = "planety.dat";

inline void eatline() { while (std::cin.get() != '\n') continue; }

int main()
{
    Planet pl;
    cout << fixed << right;

    ifstream fin;
    fin.open(file,ios_base::binary | ios_base::in);

    if (fin.is_open())
    {
        cout << "Oto aktualna zawartość pliku " <<file<<": ";
        while (fin.read((char *) &pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": " << setprecision(0) << setw(12)
                 << pl.population << setprecision(0) << setw(6) << pl.g << endl;
        }
        fin.close();
    }

    ofstream fout(file, ios_base::binary | ios_base::out | ios_base::app);

    if (!fout.is_open())
    {
        cerr << "Nie mozna otworzyć pliku " << file << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Podaj nazwę planety: (koniec, aby zakończyć)"<< endl;
    cin.get(pl.name, 20);
    
    while (pl.name[0] != '\0')
    {
        cout << "Podaj zaludnienie planety: ";
        cin >> pl.population;
        cout << "Podaj przyspieszenie grawitacyjne na planecie: ";
        cin >> pl.g;
        eatline();
        fout.write((char *) &pl, sizeof pl);
        cout << "Podaj nazwę planety (aby zakończyć, wprowadź pusty wiersz):\n";
        cin.get(pl.name, 20);
    }

    fout.close();
    fin.clear();
    fin.open(file, ios_base::in | ios_base::binary);

    if (fin.is_open())
    {
        cout << "Oto nowa zawartość pliku " << file << ":\n";
        while (fin.read((char *) &pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": " << setprecision(0) << setw(12) << pl.population
                << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }

    cout << "Koniec.\n";
    return 0;
}








