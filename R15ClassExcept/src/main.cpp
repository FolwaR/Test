#include <iostream>
#include <new>
#include "sales.h"

using namespace std;


int main()
{   
    double vals1[12] = 
    {
        1120, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };

    double vals2[12] = 
    {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 25
    };

    Sales sales1(2011, vals1, 12);

    LabeledSales sales2("Blogstar", 2012, vals2, 12);

    
    cout << "Pierwszy blok try: \n";

    try
    {
        int i = 0;
        cout << "Rok = " <<sales1.Year() <<endl;
            
        for (i  = 0; i < 12; ++i)
        {
            cout << sales1[i] << " ";
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Rok = " << sales2.Year() << endl;
        cout << "Etrykieta: " << sales2.Label() << endl;    
        for (i = 0; i <= 12; ++i)
        {   
            cout << sales2[i] << "  ";
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Koniec pierwszego bloku try!\n";
    }
    
    catch (LabeledSales::nbad_index & bdi)
    {
        cout << bdi.what();
        cout << "Firma: " << bdi.label_val() <<endl;
        cout << "Niepoprawny index: " << bdi.bi_val() << endl;
    }

    catch (Sales::bad_index & bi)
    {
        bi.what();
        cout << "Niepoprwany index: " << bi.bi_val() <<endl;    
    }

    cout << "Kolejny blok try: \n";


    try
    {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "Koniec dsrugiego bloku try!\n";
    }
    catch (LabeledSales::nbad_index & bdi)
    {
        cout << bdi.what();
        cout << "Firma: " << bdi.label_val() <<endl;
        cout << "Niepoprawny index: " << bdi.bi_val() << endl;
    }
    catch (Sales::bad_index & bi)
    {
        cout << bi.what();
        cout << "Niepoprwany index: " << bi.bi_val() <<endl;
    }

    cout << "Koniec\n";    

    return 0;
}

