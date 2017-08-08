#include "tv.h"
#include <iostream>

bool Tv::volup()
{
    if (volume < maxVal)
    {
        volume++;
        return true;
    }
    else 
        return false;
}


bool Tv::voldown()
{
    if (volume > minVal)
    {
        volume--;
        return true;
    }
    else
        return false;

}


void Tv::chanup()
{
    if (chanel < maxchanel)
        chanel++;
    else
        chanel = 1; 
}


void Tv::chandown()
{
    if (chanel > 1)
        chanel--;
    else
        chanel = maxchanel;
}


void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "Telewizor jest " << (state == OFF ? "Wyłączony" : "Włączony") << endl;
    
    if (state == ON)
    {
        cout << "Głośność: " << volume << endl;
        cout << "Program: " << chanel <<endl;
        cout << "Tryb: " << (mode == Antena ? "antena" : "kabel") << endl;
        cout << "Wejjście = " << (input == TV ? "TV" : "DVD") <<endl;
    }
}
