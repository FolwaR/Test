// stone.cpp -- konwersje wartoœci typów liczbowych na obiekty w³asnego typu
// kompilowaæ ze stonewt.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"

void display(const Stonewt & st, int n);
int main()
{
    Stonewt incognito = 275; // inicjalizacja konstruktorem
    Stonewt wolfe(285.7);    // równowa¿ne instrukcji: Stonewt wolfe = 285.7;
    Stonewt taft(21, 8);

    cout << "Celebryta wa¿y³ ";
    incognito.show_stn();
    cout << "Detektyw wa¿y³ ";
    wolfe.show_stn();
    cout << "Prezydent wa¿y³ ";
    taft.show_lbs();
    incognito = 276.8;   // konwersja konstruktorem
        taft = 325;          // równowa¿ne instrukcji: taft = Stonewt(325);
    cout << "Po obiedzie celebryta wa¿y ";
    incognito.show_stn();
    cout << "Po obiedzie prezydent wa¿y ";
    taft.show_lbs();
    display(taft, 2);
    cout << "A zapaœnik wa¿y jeszcze wiêcej.\n";
    display(427, 2);
    cout << "Nie pozosta³ kamieñ na kamieniu\n";
    return 0;
}

void display(const Stonewt & st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Oho! ";
        st.show_stn();
    }
}

