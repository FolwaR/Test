#!/usr/bin/env python3

import shelve

class Person():
    def __init__(self, name = "noName", surname = "noName", job = "noName", age = 0, pay = 0):
        self.name = name
        self.surname = surname
        self.age = age
        self.job = job
        self.pay = pay

    def __str__(self):
        return "Obiekt klasy: {} | name = {}, surname = {}, age = {}, job = {}, pay = {}".format(
                self.__class__.__name__, self.name, self.surname, self.age, self.job, self.pay)

    def giveRise(self, procent):
        self.pay *= (1 + procent)



class Menager(Person):
    def __init__(self, name, surname, age, pay):
        Person.__init__(self,name, surname, "Manager", age, pay)
    
    def giveRise(self, procent):
        Person.giveRise(self, procent + 0.1)


def create_new_DataBase():
    dbName = input("Podaj nazwę pliku bazy danych klasy Person: ")
    db = shelve.open(dbName)
    recName = input("Podaj nazeę rekordu: ")
    db[recName] = 


def display_menu():
    print("""
 Wybierz opcje:
 1) Nowa baza danych
 2) Wyświetl baze danych
 3) Modyfikuj bazę danych
 4) Koniec
    *************************
    Twoj wybór:"""
    , end=" ")
    return int(input())

"""
def main():

    wybor = display_menu()

    if wybor == 1:
        create_new_DataBase();
    elif wybor == 2:
        show_DataBase();
    elif wybor == 3:
        modify_DataBase();
    elif wybor == 4:
        print("Koniec programu")
    else:
        print("Nieoczeniwany input!")
"""
if __name__=="__main__":
    #main()
    Bob = Person("Bob", "Shmit", "Soft", 42, 1000)
    Sue = Person("Sue", "Bronks", "Hard", 46, 2000)
    Tom = Menager("Tom", "Samakin", 40, 3000)

    print(Bob)
    print(Sue)
    print(Tom)





