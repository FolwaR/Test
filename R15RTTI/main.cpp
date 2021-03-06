// rtti1.cpp -- używanie operatora dynamic_cast
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

using namespace std;


class Grand
{
    private:
        int hold;
    public:
        Grand(int h = 0) : hold(h) {}
        virtual void Speak() const { cout << "Jestem klasa Grand!\n"; }
        virtual int Value() const { return hold; }
};

class Superb : public Grand
{
    public:
        Superb(int h = 0) : Grand(h) {}
        void Speak() const { cout << "Jestem klasa Superb!!\n"; }
        virtual void Say() const
        { cout << "Przechowuję wartość klasy Superb, która wynosi " << Value() << "!\n";}
};

class Magnificent : public Superb
{
    private:
        char ch;
    public:
        Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
        void Speak() const { cout << "Jestem klasa Magnificent!!!\n"; }
        void Say() const { cout << "Przechowuję znak " << ch <<
            " oraz liczbę " << Value() << "!\n"; }
};

Grand * GetOne();

int main()
{
    std::srand(std::time(0));
    Grand * pg;
    Superb * ps;

    for (int i = 0; i < 5; i++)
    {
        pg = GetOne();
        cout << "Teraz przetwarzam obiekt klasy: " << typeid(*pg).name() << endl;
        pg->Speak();
        if (ps = dynamic_cast<Superb *>(pg))
            ps->Say();

        if (typeid(Magnificent) == typeid(*ps))
             cout << "Tak jest wspaniały jak ty!\n";

    }
    return 0;
}

Grand * GetOne() // generuje losowo jeden z trzech rodzajów obiektów
{
    Grand * p;
    switch (std::rand() % 3)
    {
        case 0: p = new Grand(std::rand() % 100);
                break;
        case 1: p = new Superb(std::rand() % 100);
                break;
        case 2: p = new Magnificent(std::rand() % 100,
                        'A' + std::rand() % 26);
                break;
    }
    return p;
}

