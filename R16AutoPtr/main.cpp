#include <iostream>
#include <memory>

using namespace std;

class Klasa
{
private:
    string napis;
public:
    
    Klasa(const string s = "NONE") : napis(s) { cout << "Wywołano konstruktor klasy" << endl; }
    ~Klasa() { cout << "Wywołano destruktor klasy" << endl; }
    
    void show() const { cout << napis << endl; }

};

unique_ptr<Klasa> fdupa();
int main()
{
    {
        Klasa * ptr1 = new Klasa {"Dupa"};
        delete ptr1;
    }

    {
        auto_ptr<Klasa> aptr(new Klasa("DUPA"));
        auto_ptr<Klasa> aptr2;
        aptr2 = aptr;
        aptr2->show();    
    }

    {
        unique_ptr<Klasa> uptr2;
        uptr2 = fdupa();
    }

    {
        shared_ptr<Klasa> sptr(new Klasa("dupa"));
        shared_ptr<Klasa> sptr2;
        sptr2 = sptr;
        sptr->show();
        sptr2->show();
    }


    return 0;
}

unique_ptr<Klasa> fdupa()
{
    unique_ptr<Klasa> uptr(new Klasa("dupa"));
    return uptr;
}
