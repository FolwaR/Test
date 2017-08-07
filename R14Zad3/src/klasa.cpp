#include "klasa.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;

void Worker::Get()
{
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
    cout << "Podaj imie i nazwisko kelnera: \n";
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



const char * Singer::pv[] = { "inny", "alt", "kontralt", "sopran", "bas","baryton", "tenor" };

void Singer::Get()
{
	cout << "Podaj skale glosu piosenkarza: ";
	
	for (int i = 0; i < Vtypes; i++)
	{
		cout << i <<": "<< pv[i] << " ";
		if ((i % 4) == 3)
			cout << endl;
	}	
	cout << endl;
	
	while (cin >> tone && (tone < 0 || tone >= Vtypes))
		cout << "Podane dane są błędne!"<<endl;
	while (cin.get() != '\n')
		continue;

}


void Singer::Show() const
{
    cout << "Kategoria piosenkarz: \n";
	Worker::Data();
	Data();	
}

void Singer::Data() const
{
	cout << "Skala glosu: "<<pv[tone]<<endl;
}

void Singer::Set()
{
    cout << "Podaj imię i nazwisko piosenkarza: \n";
	Worker::Get();
	Get();
}


void SingerWaiter::Get()
{
    Singer::Get();
    Waiter::Get();
}


void SingerWaiter::Show() const
{
    cout << "Kategoria: śpiewający kelner\n";
    Worker::Data();
    Data(); 
}


void SingerWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}


void SingerWaiter::Set()
{
    cout << "Podaj imię i nazwisko świewającego kelnera: ";
    Worker::Get();
    Get();
}




