#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string wyraz;    

    cout << "Podaj stringa: ('koniec', aby zakonczyc): ";
    
    while (cin >> wyraz && wyraz != "koniec")
    {
        sort(wyraz.begin(), wyraz.end());
        while (next_permutation(wyraz.begin(), wyraz.end()))
            cout << wyraz<<endl;
        cout << "Podaj kolejny wyraz: ";
    }

    return 0;
}


