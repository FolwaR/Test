#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main()
{
    typedef pair<int, string> Pair;
    typedef map<int, string> Map;

    Map osoby;

    osoby.insert(Pair(10974, "Lukasz"));
    osoby.insert(Pair(10974, "Lukaszaa"));
    osoby.insert(Pair(109744, "Lukaszaa"));
    osoby.insert(Pair(1045974, "Lukasz"));

    auto it = osoby.begin();

    for (auto it = osoby.begin(); it != osoby.end(); it++)
        cout << (*it).first << " " << (*it).second << endl;


    cout << osoby[109744] << endl;    

    return 0;
}


