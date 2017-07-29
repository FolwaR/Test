#include <iostream>
#include "student.h"

using namespace std;

int ile_studentow = 2;
int ile_ocen = 5;
int main()
{
	Student student[ile_studentow] = Student(ile_ocen);

	for (int i = 0; i <ile_studentow; i++)
		cout << student[i]<<endl;

	for (int i = 0; i < ile_studentow; i++)
	{
		cin >> student[i];
		for (int j = 0; j < ile_ocen; j++)
		{
			cout << "Podaj ocene ["<<j<<"]: ";
			int ocena;
			while(!(cin >> ocena))
			{
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout<<"Podaj poprawna liczbe chuju: ";
										
			}
		
			student[i][j] = ocena;
			
		}

	}
	for (int i = 0; i <ile_studentow; i++)
		cout << student[i]<<endl;


	return 0;
}
