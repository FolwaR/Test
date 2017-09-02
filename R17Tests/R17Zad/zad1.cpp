#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file;

    file.open("plik.txt", ios_base::in);

    if (!file.is_open())
    {
        cerr << "Nie udało się otworzyć pliku"<< endl;
        exit(EXIT_FAILURE);
    }
    cout << "Metoda pierwsza" << endl;
    char c;
    int ile = 0;
    while (file.get(c) && c != '$')
    {
        ile ++;
    }

    file.putback(c);
    cout << ile << endl;
    ile = 0;
    file.clear();
    file.close();

   cout << "Metoda druga: " << endl;
    file.open("plik.txt", ios_base::in);
    if (!file.is_open())
    {
        cerr << "Nie udało się otworzyć pliku"<< endl;
        exit(EXIT_FAILURE);
    }
   while (file.peek() != '$')
   {
        file.get(c);
        ile++;
   }
   cout << ile << endl;
   file.clear();
   file.close();

    return 0;
}


