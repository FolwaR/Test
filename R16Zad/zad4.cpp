#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;

template<typename T>
void super(T * array, int ile);

int main(int argc, char * argv[])
{
    srand(time(0));
  
    int SIZE = 5;  

    int tab1[SIZE];

    double tab2[SIZE];

    string tab3[7] { "zara", "ala", "biedronka", "cmntarz", "flet", "ala", "ala" };

    for (int i = 0; i < SIZE; i++)
        tab1[i] = (rand() % 100)+1;

    cout << ((rand() % 100)+1)/3.15789;
    
    for (int i = 0; i < SIZE; i++)
        tab2[i] = ((rand() % 100)+1)/1.123;
    

    super(tab1,SIZE);
    super(tab2, SIZE);
    super(tab3, 7);

    return 0;
}


template<typename T>
void super(T * array, int ile)
{
    vector<T> vec;

    copy(array, array+ile, insert_iterator<vector<T>>(vec,vec.begin()));

    ostream_iterator<T, char> outIter(cout, " ");
    cout << endl;   

    map<T,int> myMap;
 
    auto itr = vec.begin();
    while ( itr < vec.end() )
    {
        myMap[*itr] = count(vec.begin(), vec.end(), (*itr));
        itr++;
    }
   
    for (auto p : myMap)
        cout << "myMap[" << p.first << "] = " << myMap[p.first] << endl; 
}

