#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int main(int argc, char * argv[])
{
    ifstream inFile1;
    ifstream inFile2;
    ofstream outFile;
    string inFile1_name;
    string inFile2_name;
    string outFile_name;
 
    if (argc > 1)
    {
        inFile1_name = argv[1];
        inFile2_name = argv[2];
        outFile_name = argv[3];
    }
    else
    {
        cout << "Usage: program inFile1 inFile2 outFile";
    }

    inFile1.open(inFile1_name, ios_base::in);
    if (!inFile1.is_open())
    {
        cout << "Nie udało się otworzyć pliku: " << inFile1_name << endl;
        exit(EXIT_FAILURE);
    }

    inFile2.open(inFile2_name, ios_base::in);
    if (!inFile2.is_open())
    {
        cout << "Nie można otworzyć pliku: " << inFile2_name << endl;
        exit(EXIT_FAILURE);
    }
  
    outFile.open(outFile_name, ios_base::out);
    if (!outFile.is_open())
    {
        cout << "Nie udało się otworzyć plku: " << outFile_name << endl;
        exit(EXIT_FAILURE);
    }

    string temp1;
    string temp2;

    vector<string> names;

    while (!(inFile1.eof() && inFile2.eof()))
    {
        getline(inFile1, temp1);
        getline(inFile2, temp2);
        if (!inFile1.eof())
            names.push_back(temp1);
        if (!inFile2.eof())
            names.push_back(temp2);
    }

    set<string> all_names;

    copy(names.begin(), names.end(), insert_iterator<set<string>>(all_names, all_names.begin()));

    ostream_iterator<string,char> outIter(outFile,"\n");

    copy(all_names.begin(), all_names.end(), outIter);




    inFile1.close();
    inFile2.close();
    outFile.close();

    return 0;
}
















