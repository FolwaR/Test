#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<int> Lotto(int, int);


int main()
{
    srand(time(0));
    vector<int> wynik;
    wynik = Lotto(50, 6);

    return 0;
}

vector<int> Lotto(int pola, int ilosc)
{
    vector<int> liczbyMozliwe;
    vector<int> wynik;

    for (int i = 1; i < pola + 2; i++)
        liczbyMozliwe.push_back(i);

    ostream_iterator<int, char> outIter(cout, " ");
    random_shuffle(liczbyMozliwe.begin(), liczbyMozliwe.end(), [](int i)->int{ return (rand()%i); });
    copy(liczbyMozliwe.begin(), liczbyMozliwe.begin()+ilosc, insert_iterator<vector<int>>(wynik,wynik.begin()));

    copy(wynik.begin(), wynik.end(), outIter);
    cout << endl;
    
    return wynik;
}




