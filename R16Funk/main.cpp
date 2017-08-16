#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <map>
#include <valarray>

using namespace std;

inline void outint(int & elem) { cout << elem << " "; }


template <typename T>
class TooBig
{
private:
    T limit;
public:
    TooBig(T lm) : limit(lm) {}
    bool operator()(T lim) { return lim < limit; }
};


inline int ppow(int & n) { return n*n; }


int main()
{
    TooBig<int> f100(100);

    int vals[10] {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

    list<int> yadayada(vals, vals+10);
    list<int> etcetera(vals, vals+10);

    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    yadayada.remove_if(f100);
    for_each(yadayada.begin(), yadayada.end(), outint);

    list<int> myList {1,2,3,4,5,6,7,8,9,10};
    list<int> myList2 {1,2,3,4,5,6,7,8,9,10};
    
    cout << endl;

    for_each(myList.begin(), myList.end(), outint);


    map<int, string> myMap;

    myMap[0] = "dupa";

    cout << myMap[0] << endl;

    ostream_iterator<int, char> out(cout, " ");
    cout << endl;
    transform(myList.begin(), myList.end(), out ,ppow);
    cout << endl;
    transform(myList.begin(), myList.end(), myList2.begin(), out, plus<int>());
    cout << endl;

    valarray<int> myArray {1,2,3,4,5,6,7,8,9,10};
    valarray<int> myArray2 {1,2,3,4,5,6,7,8,9,10};
    valarray<int> Out;
    
    Out = myArray - myArray2;
    
    copy(begin(Out), end(Out), out);
    cout << endl;

    return 0;
}




