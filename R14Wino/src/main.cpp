#include <iostream>
#include "wino.h"

using namespace std;

int main()
{
    int rocznik[4] = { 2016,2017,2019,2020 };
    int sztuk[4] = { 20,21,10,48 };

    Wino w1("Jabol", 4, rocznik, sztuk);
    w1.show();
    
    Wino w2 = w1;
    w2.show();

    Wino w3;
    w3.show();
    w3 = w2;
  
    w3.show();
    return 0;
}
