#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(0));
    vector<int> vi0;
    vector<int> vi;
    list<int> li;

    cout << "Podaj liczbe: ";
    int ile_liczb = 0;
    cin >> ile_liczb;

    for (int i = 0; i < ile_liczb; i++)
        li.push_back((rand()%100)+1);
    
    clock_t vec_start = clock();
    copy(li.begin(), li.end(), insert_iterator<vector<int>>(vi, vi.begin()));
    clock_t vec_end = clock(); 
    double vec_time = double(vec_end - vec_start) / CLOCKS_PER_SEC;
    vec_start = clock();
    sort(vi.begin(), vi.end());
    vec_end = clock();
    double vec_time_sort = double(vec_end - vec_start) / CLOCKS_PER_SEC;

    vec_start = clock();
    copy(vi.begin(), vi.end(), front_insert_iterator<list<int>>(li));
    vec_end = clock();
    double li_time_copy = double(vec_end - vec_start) / CLOCKS_PER_SEC;

    cout << "Czas kopiowania i sortowania vektora: " << vec_time + vec_time_sort + li_time_copy << endl;

    li.clear();
    for (int i = 0; i < ile_liczb; i++)
        li.push_back((rand()%100)+1);

    vec_start = clock();
    li.sort();
    vec_end = clock();
    double li_time_sort = double(vec_end - vec_start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania listy: " << li_time_sort << endl;
    

/*
    vec_start = clock();
    copy(vi0.begin(), vi0.end(), insert_iterator<list<int>>(li, li.begin()));
    vec_end = clock();
    double li_time = double(vec_end - vec_start) / CLOCKS_PER_SEC;
    vec_start = clock();
    li.sort();
    vec_end = clock();
    double li_time_sort = double(vec_end - vec_start) / CLOCKS_PER_SEC;    


    ostream_iterator<int, char> outIter(cout, " ");
*/
/*
    copy(vi.begin(), vi.end(), outIter);
    cout << endl;
    copy(li.begin(), li.end(), outIter);
    cout << endl;
*/
    

    return 0;
}


