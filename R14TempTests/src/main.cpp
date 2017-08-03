#include <iostream>
#include "tempmenb.h"
#include "frid2temp.h"

using namespace std;


int main()
{

	cout << "------------------------------------------------------------------\n";
	cout << "************************ TEMPMEMB.H ******************************\n";
	cout << "------------------------------------------------------------------\n";
	beta<double> guy(3.5,3);
	cout << "T jako double" << endl;
	guy.show();
	cout << "V najpierw określono jako T, czyli double a nastepnie jako int\n";
	cout << guy.blab(10, 2.3) <<endl; 
	cout << "U okreslono jako int" <<endl;
	cout << guy.blab(10.0, 2.3) <<endl;
	cout << "U okreslono jako double" <<endl;
	cout << "Koniec!\n" << endl;



	cout << "------------------------------------------------------------------\n";
	cout << "************************ FRID2TMP.H ******************************\n";
	cout << "------------------------------------------------------------------\n";
	cout << "Brak zadeklarowanych obiektów" << endl;
	count();	

	HasFriend<int> hf1(10);
	cout << "Po dekleracji hf1\n";
	count();

	HasFriend<int> hf2(20);	
	cout << "Po dekleracji hf2\n";
    count();

	HasFriend<double> hfd1(20.2);
    cout << "Po dekleracji hfd12\n";
    count();

	report(hf1);
	report(hf2);
	report(hfd1);
	
	cout << "Koniec!\n";

	return 0;
}



