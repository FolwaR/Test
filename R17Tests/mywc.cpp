#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
    string name;
    
    ifstream file;

    if (argc > 1)
    {
        name = argv[1];
            
        file.open(name.c_str(), ios_base::in);
        
        if (!file.is_open())
            exit(1);     
    }

    char c;
    int ile=0;
    while (file.get(c))
        ile++;

    cout << "W pliku jest " << ile << " znaków"<< endl;

    file.clear();
    file.close();


    return 0;
}

