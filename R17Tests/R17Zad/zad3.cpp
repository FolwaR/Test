#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
    ifstream fin;
    ofstream fout;

    string fout_name;
    string fin_name;

    if (argc > 1)
    {
        fin_name = argv[1];
        fout_name = argv[2];
    }

    fin.open(fin_name, ios_base::in);
    if (!fin.is_open())
    {
        cout << "Nie udało się otworzyć pliku ;/" << fin_name <<endl;
        exit(EXIT_FAILURE);
    }
    fout.open(fout_name, ios_base::out);
    if (!fout.is_open())
    {
        cout << "Nie udało się otworzyć pliku: " << fout_name << endl;
        exit(EXIT_FAILURE);
    }
    cout << "DUPA";
    char c;
    while (fin.get(c))
    {
        if (c != ';')
            fout.put(c);
    }

    fout.close();

    fin.close();

    return 0;
}

