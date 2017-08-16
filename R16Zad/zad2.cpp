#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;



int main(int argc, char *argv[])
{
    string file_name;

    if (argc > 1)
        file_name = argv[1];

    ifstream in_file;
    
    try
    {   
        in_file.open(file_name);
        if (!in_file.is_open())
            throw string("Nie ma takiego pliku. KONIEC!\n");
    }
    catch (string & msg)
    {
        cout << msg;
        exit(1);
    }

    vector<string> word_frim_file;

    string temp;
    while (in_file >> temp)
        word_frim_file.push_back(temp);

    ostream_iterator<string, char> outiter(cout, " ");
    copy(word_frim_file.begin(), word_frim_file.end(), outiter);
        

    in_file.close();

    return 0;
}


