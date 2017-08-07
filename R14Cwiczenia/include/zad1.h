#ifndef _ZAD1_H_
#define _ZAD1_H_

#include <iostream>
#include <cstring>

class Frabjous
{
    private:
        char fab[20];
    
    public:
        Frabjous(const char * c = "C++") { strncpy(fab, c, 19); fab[19] = '\0';}; 
        virtual void tell() const {std::cout << fab << std::endl;}    
    
};

class Gloam : private Frabjous
{
    private:
        int grip;
    
    public:
        Gloam(int i, const char * c = "C++") : grip(i), Frabjous(c) {}
        Gloam(int i, Frabjous & nf) : grip(i), Frabjous(nf) {}
        void tell() const;
};

void Gloam::tell() const
{
    std::cout << "cout grimp: "<< grip << ", ";
    Frabjous::tell();
}






#endif

