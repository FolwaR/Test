#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{

    string file_name;

    if (argc > 1)
        file_name = argv[1];
    

    ofstream fout(file_name, ios_base::out | ios_base::app);
    
    if (!fout.is_open())
    {
        cout << "Nie duało się otworzyć  pliku!" << endl;
        exit(EXIT_FAILURE);
    }


    char c;
    
    while (cin.peek() != '\n')
    {
        cin.get(c);
        fout.put(c);
    }

    fout.clear();
    fout.close();

    return 0;
}
