#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>

class Person
{
    private:
    typedef std::string string;

    string name;
    string surname;
    
    int age;    

    protected:
    void data() const;

    public:
    Person() : name("noName"), surname("noSurname"), age(0) {}
    Person(const string n, const string sur, int a) : name(n), surname(sur), age(a) {}
    ~Person();
    
    virtual void get();
    virtual void show() const;

};


class Gunslinger : public Person
{
    private:
    double timeToShoot;
    int naciecia;
    typedef std::string string;

    protected:
    void data() const;

    public:
    Gunslinger() : Person(), timeToShoot(0), naciecia(0) {}
    Gunslinger(double tS, int nac, Person & pp) : timeToShoot(tS), naciecia(nac), Person(pp) {}
    Gunslinger(double tS, int nac, const string n, const string sur, int a) : timeToShoot(tS), naciecia(nac), Person(n,sur,a) {}
    ~Gunslinger() {};

    virtual void show() const;
    virtual void get();
};


class PokerPlayer
{
    private:
    

    public:
    PokerPlayer();
   ~PokerPlayer();
};










#endif
