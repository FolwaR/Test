#include "port.h"
#include <iostream>
#include <cstring>

int Port::ile_sztuk = 0;

Port::Port(const char * prod, const char * sty, int no)
{
	producent = new char [strlen(prod)+1];
	strcpy(producent, prod);

	strncpy(style, sty, 19);
	style[19] = '\0';

	ile_sztuk += 1;
	bottels = no;
}

Port::Port(const Port & po)
{
	ile_sztuk++;

	producent = new char [strlen(po.producent)+1];
	strcpy(producent, po.producent);

	strncpy(style, po.style, 19);
	producent[19] = '\0';

	bottels = po.bottels;
}

Port::~Port()
{
	ile_sztuk--;
	delete [] producent;
}
void Port::show() const
{
	std::cout << "Producent: "<<producent<<std::endl;
	std::cout << "Styl: "<<style<<std::endl;
	std::cout << "Ilosc butelek: "<<bottels<<std::endl;

}

int Port::ile_obiektow()
{
	return ile_sztuk;
}


int Port::ile_bottels() const
{
	return bottels;
}


Port & Port::operator=(const Port & po)
{
	if (this == &po)
		return *this;
	else
	{
		delete [] producent;
		producent = new char [strlen(po.producent)+1];
    	strcpy(producent, po.producent);

    	strncpy(style, po.style, 19);
   		producent[19] = '\0';

    	bottels = po.bottels;

		return *this;
	}
}

Port & Port::operator+=(int n)
{
	bottels += n;
	return *this;
}

Port & Port::operator-=(int n)
{
	bottels -= n;
	
	if (bottels < 0)
		bottels = 0;

	return *this;
}


std::ostream & operator<<(std::ostream & out, const Port & po) 
{
	out << "Producent: "<<po.producent<<", styl: "<<po.style<<", ilosc butelek: "<<po.bottels<<std::endl;
	return out;
}


int VintagePort::ile_sztuk_vintage = 0;

VintagePort::VintagePort(const char * niN, int ye, const char * prod, const char * sty, int no) : Port(prod, sty, no)
{
	nickname = new char [strlen(niN)+1];
	strcpy(nickname, niN);

	year = ye;
	ile_sztuk_vintage++;
}

VintagePort::VintagePort(const char * niN, int ye, Port & po) : Port(po)
{
    nickname = new char [strlen(niN)+1];
    strcpy(nickname, niN);

    year = ye;
    ile_sztuk_vintage++;

}


VintagePort::~VintagePort()
{
	ile_sztuk_vintage--;
	delete [] nickname;
}


VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
    nickname = new char [strlen(vp.nickname)+1];
    strcpy(nickname, vp.nickname);

    year = vp.year;
    ile_sztuk_vintage++;

} 
     
VintagePort & VintagePort::operator=(VintagePort & vp)
{
	if (this == &vp)
		return *this;	

	else{
		this->Port::operator=(vp);
		delete [] nickname;
		
		nickname = new char [strlen(vp.nickname)+1];
	    strcpy(nickname, vp.nickname);

    	year = vp.year;
		return *this;
	}
	
}


void VintagePort::show() const
{
	Port::show();
	std::cout <<"Nickanme: "<<nickname<<std::endl;
	std::cout <<"Year: "<<year<<std::endl;
}


int VintagePort::ile_obiektow()
{
	return ile_sztuk_vintage;
}


std::ostream & operator<<(std::ostream & out, const VintagePort & vp)
{
	
	out << (const Port &) vp << std::endl;
	out << "Nickname: " << vp.nickname << ", year: "<<vp.year<<std::endl;
	return out;
}












