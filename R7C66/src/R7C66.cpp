

#include <iostream>
using namespace std;

int fill_array(double *tab, const int size);
void show_array(const double *tab, const int size);
void reverse_array(double *tab, const int size);
int main()
{
	const int MAX = 10;
	int ile_bylo = 0;
	double my_array[MAX];

	cout << "Calling fill array function! "<<endl;

	ile_bylo = fill_array(my_array, MAX);
	cout <<endl;
	cout <<"Podano: "<<ile_bylo<<" liczb."<<endl;
	cout <<endl;
	cout << "Calling show array function! " << endl;
	show_array(my_array, ile_bylo);
	cout <<endl;
	cout << "Calling reverse array function! " << endl;
	reverse_array(my_array, ile_bylo);
	show_array(my_array, ile_bylo);
	cout <<endl;
	return 0;
}


int fill_array(double *tab, const int size)
{
	int ile_elementow = 0;
	int value = 0;

	cout << "Prosze o podanie " <<ile_elementow+1 <<" elementu: ";
	while((cin>>value))
	{
		*(tab + ile_elementow) = value;
		ile_elementow++;
		if(((ile_elementow) >= size))
			break;
		cout << "Prosze o podanie " <<ile_elementow+1 <<" elementu: ";

	}
	return ile_elementow;
}


void show_array(const double *tab, const int size)
{
	for (int i = 0; i < size; i++)
		cout <<"Element " << i + 1 << " ma wartosc: "<< *(tab+i)<<endl;
}


void reverse_array(double *tab, const int size)
{
	int temp = 0;

	for (int i = 0; i < (size / 2); i++)
	{
		temp = *(tab+i);
		*(tab + i) = *(tab + (size-1)-i);
		*(tab + (size-1)-i) = temp;
	}

}
