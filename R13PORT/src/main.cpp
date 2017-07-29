#include "port.h"
#include <iostream>

using namespace std;

int main()
{
{
	Port nowe("JabloPolska", "Tradycyjny",10);
	
	Port kopia_nowe = nowe;

	Port nic;


	cout << nowe;
	cout << kopia_nowe;
	cout << nic;

	nic = Port("Zbyszko", "innyniztradycyjnyhehehheheheh",12);

	cout <<nic;

	nowe += 5;

	cout << nowe;
	nowe.show();

	nowe-=10;

	cout <<nowe;

	cout << Port::ile_obiektow()<<endl;


	VintagePort PortV("Dupa", 1994, nowe);
	VintagePort PortV2 = PortV;
	
	cout << PortV<<endl;

	cout << PortV2 <<endl;


	PortV2 = PortV;

	cout << PortV2 <<endl;
	cout << Port::ile_obiektow()<<endl;
	cout << VintagePort::ile_obiektow()<<endl;;	

}
	cout << Port::ile_obiektow()<<endl;
	cout <<VintagePort::ile_obiektow()<<endl;

	return 0;
}
