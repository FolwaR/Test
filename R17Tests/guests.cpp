#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const char * file = "gosice.txt";

int main()
{
    char c;
    
    ifstream fin;
    fin.open(file);
    
    if (fin.is_open())
    {
        cout << "Oto aktualna lista gości: " << endl;

        while (fin.get(c))
            cout << c;
        
        fin.clear();
        fin.close();
    }

    ofstream fout(file, ios_base::out | ios_base::app);

    if (!fout.is_open())
    {
        cerr << "Nie udało się otworzyć pliku!";
        exit(1);
    }

    cout << "Podaj imie i nzawisko nowej osoby: ('koniec', aby zakończyć): " << endl;
    string name;

    while (getline(cin, name) && name != "koniec")
    {
        fout << name <<endl;
    }

    fout.close();


    cout << "Aktualny stan pliku: "<< endl;

    fin.open(file);

    if (fin.is_open())
    {
        cout << "Oto aktualna lista gości: " << endl;

        while (fin.get(c))
            cout << c;
        
        fin.clear();
        fin.close();
    }

    return 0;
}
