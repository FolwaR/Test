#include <iostream>
#include "Person.h"

void Person::get()
{
    std::cout << "Podaj imie: ";
    std::getline(std::cin, name);
    std::cout << "Podaj nazwisko: ";
    std::getline(std::cin, surname);
    std::cout << "Podaj wiek: ";
    std::cin >> age; 
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
}

void Person::data() const
{
    std::cout << "----------------------------------------------------";
    std::cout << "Osoba - dane: \n";
    std::cout << "Imie: " << name << ", nazwisko: " << surname << ", wiek: " << age <<std::endl;
    std::cout << "----------------------------------------------------";
}

void Person::show() const
{
    data();
}
 

void Gunslinger::get()
{
    std::cout << "Klasa gunsligner \n";
    Person::get();
    std::cout << "Podaj czas potrzeby na oddanie strzału: ";
    cin >> timeToShoot;
    
    while (cin.get() != '\n')
        continue;

    std::cout << "Podaj ilosc naciec na pistolecie: ";
    cin >> naciecia;

    while (cin.get() != '\n')
        continue;

}


void Gunslinger::data() const
{
    std::cout << "Czas potrzebny na oddanie strzału: ";
    std::cout << timeToShoot;
    
    std::cout << "Ilość nacięć na pistoilecie: ";
    std::cout << naciecia;
}


void Gunslinger::show() const
{
    Person::show();
    data();
}




