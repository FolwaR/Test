#include "klasa.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;

void Worker::Get()
{
	cout << "Podaj imie i nazwisko pracownika: ";
	getline(cin, fullname);

	cout << "Podaj numer identyfikacjyny pracowniak: ";
	cin >> id;

	cin.clear();	

	while (cin.get() != '\n')
		continue;
}


void Worker::Data() const
{
	cout << "Imie i nazwisko pracownika: " << fullname << endl; 
	cout << "Identyfikator pracownika: " << id << endl;
}



void Waiter::Set()
{
	Worker::Get();

	Get();
}


void Waiter::Get()
{
	cout << "Podaj poziom elegancji: ";
	cin >> panche;

	while (cin.get() != '\n')
		continue;
}


void Waiter::Data() const
{
	cout << "Poziom elegancji kelnera: " << panche << endl;
}


void Waiter::Show() const
{
	cout << "Kategortia kerner "<<endl;
	Worker::Data();
	Data();	
}



char * Singer::pv[] = { "inny", "alt", "kontralt", "sopran", "bas","baryton", "tenor" };

void Singer::Get()
{
	cout << "Podaj skale glosu piosenkarza: ";
	
	for (int i = 0; i < Vtypes; i++)
	{
		cout <<i<<": "<< pv[i] << " ";
		if ((i % 3) == 0)
			cout <<endl;
	}	
	cout << endl;
	
	while (cin >> tone && (tone < 0 || tone >= Vtypes))
		cout << "Podane dane są błędne!"<<endl;
	while (cin.get() != '\n')
		continue;

}


void Singer::Show() const
{
	Worker::Data();
	Data();	
}

void Singer::Data()
{
	cout << "Skala glosu: "<<pv[voice]<<endl;
}

void Singer::Set()
{
	Worker::Get();
	Get();
}











