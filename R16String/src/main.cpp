#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
    string star(80, '*');
    cout<<star<<endl; 
    string lol("dupa");
    cout << lol << endl;
    string three(lol);

    cout << three <<endl;

    const char tab[20] = "Taki tam string"; 

    string four(tab+2, tab+10);
    cout << four <<endl;


    string dupa {'D', 'U', 'P', 'A'};

    cout << dupa << endl;


    ifstream file;

    file.open("text.txt");


    if (file.is_open() == false)
        cerr << "Nie można otworzyć pliku!";

    string wiersz;

    getline(file, wiersz, ':');
    while (file)
    {
        cout << wiersz << endl;    
        getline(file, wiersz, ':');
    }


    file.close();


    cout<<star<<endl;     
          
    return 0;
}


