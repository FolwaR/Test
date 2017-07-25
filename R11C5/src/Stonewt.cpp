// stonewt.cpp -- implementacje metod klasy Stonewt
#include <iostream>
using std::cout;
#include "Stonewt.h"

// konstruuje obiekt Stonewt z warto�ci typu double
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn; // dzielenie ca�kowite
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// konstruuje obiekt Stonewt z liczby kamieni i funt�w
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt() // konstruktor domy�lny, zeruje obiekt
{
    stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt() // destruktor
{
}
// pokazuje mas� w kamieniach
void Stonewt::show_stn() const
{
    cout << stone << " kamieni, " << pds_left << " funt�w\n";
}
// pokazuje mas� w funtach
void Stonewt::show_lbs() const
{
    cout << pounds << " funt�w\n";
}

