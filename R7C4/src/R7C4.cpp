#include <iostream>

using namespace std;

double silnia(int liczba);

int main()
{
	int liczba = 0;

	cout << "Podaj liczbe, ktorje silnie chcesz policzyc (-1 konczy): ";

	cin >> liczba;

	while(liczba != -1)
	{
		cout << "Silnia z podanej liczby jest rowna: "<<silnia(liczba)<<endl;
		cout << "Podaj liczbe, ktorje silnie chcesz policzyc (-1 konczy): ";
		cin >> liczba;
	}

	return 0;
}

double silnia(int liczba)
{
	if(liczba == 0)
		return 1;
	else
		return liczba*silnia(liczba-1);
}
