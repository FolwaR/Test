#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZMIAR 45
#define FMAX 5


typedef struct filmy
{
	char tytul[ROZMIAR];
	int ocena;

}Filmy;

char *wczytaj(char *z, int ile);

int main(void)
{
	Filmy filmy[FMAX];
	int i = 0;
	int j = 0;
	puts("Podaj pierwszy tytul filmu:");
	while (i < FMAX && wczytaj(filmy[i].tytul, ROZMIAR) != NULL && filmy[i].tytul[0] != '\0')
	{
		puts("Podaj Twoja ocene <0-10>:");
		scanf_s("%d", &filmy[i++].ocena);

		while(getchar() != '\n')
		 	continue;

		puts("Podaj nastepny tytul filmu (pusty wiersz konczy program):");
	}

	if (i == 0)
		printf("Nie wpisano zadnych danych. ");

	else
		printf ("Oto lista filmow:\n");

	for (j = 0; j < i; j++)
			printf("Film: %s Ocena: %d\n", filmy[j].tytul, filmy[j].ocena);

	printf("Do widzenia!\n");
	getchar();
	getchar();


	return 0;
}

char *wczytaj(char *z, int ile)
{
	char * wynik;
	char * tutaj;

	wynik = fgets(z, ile, stdin);

	if (wynik)
	{
		tutaj = strchr(z, '\n'); // szukamy nowego wiersza
		if (tutaj) // jesli adres jest rozny od NULL
			*tutaj = '\0'; // zamieniamy znak nowego wiersza na pusty
		else
			while (getchar() != '\n')
				continue;
	}

	return wynik;

}
