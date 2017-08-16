#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<string> PobierzImiona();
map<string, int> listaGosci(vector<string> l1, vector<string> l2);

void displayVec(const vector<string> vec);

int main()
{
    vector<string> listaLolka;
    vector<string> listaBolka;    

    listaLolka = PobierzImiona();
    listaBolka = PobierzImiona();    
    
    displayVec(listaLolka);
    cout << endl;     
    displayVec(listaBolka);    
    cout << endl;
    map<string, int> listaOgolna = listaGosci(listaLolka, listaBolka);

    for (auto i : listaOgolna)
    {
        cout << "[" << i.first << "] = " << listaOgolna[i.first] << endl;
    }

    return 0;
}


vector<string> PobierzImiona()
{
    vector<string> lista;
    string temp;
    cout << "Rozpoczynam tworzenie listy, podaj imie <'koniec', aby akończyć>: ";
    while ((cin >> temp) && (temp != "koniec"))
    {
        lista.push_back(temp);
        cout << "Podaj kolejne imie: ";
    }
    cout << "Tworzenie listy zkończone" << endl;
    cin.clear();
    while (cin.get() != '\n')
        continue;
    
    return lista;
}


void displayVec(const vector<string> vec)
{
    ostream_iterator<string, char> outIter(cout, ", ");
    copy(vec.begin(), vec.end(), outIter);
}

map<string, int> listaGosci(vector<string> l1, vector<string> l2)
{
    map<string, int> tempList;

    vector<string>::iterator iter = l1.begin();

    while ( iter != l1.end())
    {
        tempList[*iter] = count(l1.begin(), l1.end(), *iter);    
        iter++;
    }
    
    iter = l2.begin();

    while ( iter != l2.end())
    {
        tempList[*iter] = count(l2.begin(), l2.end(), *iter);
        iter++;
    }

    return tempList;
}


