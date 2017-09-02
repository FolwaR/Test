#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
const int LIM = 20;

struct planet
{
    char name[LIM];
    double population;
    double g; 
};

const char * file = "planety.dat";
inline void eatline() { while (std::cin.get() != '\n') continue; }

int main()
{ 
    using namespace std;
    planet pl;
    cout << fixed;

    fstream finout; 
    finout.open(file,ios_base::in | ios_base::out | ios_base::binary);

    int ct = 0;

    if (finout.is_open())
    {
        finout.seekg(0);
        cout << "Oto aktualna zawartość pliku "
            << file << ":\n";
        
        while (finout.read((char *) &pl, sizeof pl))
        {
            cout << ct++ << ": " << setw(LIM) << pl.name << ": "
                << setprecision(0) << setw(12) << pl.population
                << setprecision(2) << setw(6) << pl.g << endl;
        }
        if (finout.eof())
            finout.clear();
        else
        {
            cerr << "Błąd przy próbie odczytu pliku " << file << ".\n";
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        cerr << "Nie można otworzyć pliku " << file << " -- koniec pracy programu.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Podaj numer rekordu, który chcesz zmienić: ";
    long rec;
    cin >> rec;
    eatline();

    if (rec < 0 || rec >= ct)
    {
        cerr << "Nieprawidłowy numer rekordu -- koniec pracy programu\n";
        exit(EXIT_FAILURE);
    }

    streampos place = rec * sizeof pl;
    finout.seekg(place);
    if (finout.fail())
    {
        cerr << "Błąd podczas wyszukiwania pozycji\n";
        exit(EXIT_FAILURE);
    }
    
    finout.read((char *) &pl, sizeof pl);
    cout << "Twój wybór:\n";
    cout << rec << ": " << setw(LIM) << pl.name << ": "
        << setprecision(0) << setw(12) << pl.population
        << setprecision(2) << setw(6) << pl.g << endl;
    if (finout.eof())
        finout.clear();

    cout << "Podaj nazwę planety: ";
    cin.get(pl.name, LIM);
    cout << "Podaj zaludnienie planety: ";
    cin >> pl.population;
    cout << "Podaj przyspieszenie grawitacyjne na planecie: ";
    cin >> pl.g;
    finout.seekp(place);
    finout.write((char *) &pl, sizeof pl) << flush;

    if (finout.fail())
    { 
        cerr << "Błąd przy próbie zapisu\n";
        exit(EXIT_FAILURE);
    }
    ct = 0;
    finout.seekg(0);
    cout << "Oto nowa zawartość pliku " << file << " :\n";
    while (finout.read((char *) &pl, sizeof pl))
    {
       cout << ct++ << ": " << setw(LIM) << pl.name << ": "
          << setprecision(0) << setw(12) << pl.population
         << setprecision(2) << setw(6) << pl.g << endl; 
    }
    finout.close();
    cout << "Koniec.\n";
    return 0;
}














