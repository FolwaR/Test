#include <iostream>
#include "tv.h"
using namespace std;

int main()
{
    Tv s42;
   
    cout << "Początkowe ustawienia televizora S42: \n";
    s42.settings();

    s42.onoff();   
    s42.chanup();
    
    cout << "Nowe ustawniena telewizora: \n";
    s42.settings();

    Remote gray;

    gray.set_chan(s42, 10);
    gray.volup(s42);
    gray.volup(s42);
    
    cout << "Ustawnienia telewizora pouzyciu pilota: \n";
    s42.settings();
 
    Tv s58(Tv::ON);
    s58.set_mode();
    gray.set_chan(s58,28);

    cout << "Ustawienia teleziora S58: \n";
    s58.settings();
 

    return 0;
}
