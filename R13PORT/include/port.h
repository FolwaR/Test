#ifndef _PORT_H_
#define _PORT_H

#include <iostream>

class Port
{
	private:
		static int ile_sztuk;
		char * producent;
		char style[20];
		int bottels;
	public:
		Port(const char * prod = "JabolZOO", const char * sty = "noStyle", int no = 0);
		Port(const Port &);
		virtual ~Port();

		virtual void show() const;
		static int ile_obiektow();
		int ile_bottels() const;

		friend std::ostream & operator<<(std::ostream &, const Port &);
		Port & operator=(const Port &);
		Port & operator+=(int n);
		Port & operator-=(int n);
		
};


class VintagePort : public Port
{
	private:
		char * nickname;
		int year;
		static int ile_sztuk_vintage;
	public:
		VintagePort(const char * niN = "nic", int ye = 0, const char * prod = "JabolZOO", const char * sty = "noStyle", int no = 0);
		VintagePort(const char * niN, int ye, Port &);
		~VintagePort();
		VintagePort(const VintagePort &);
		

		virtual void show() const;
		static int ile_obiektow();
		VintagePort & operator=(VintagePort & vp);
		friend std::ostream & operator<<(std::ostream &, const VintagePort &);


};

#endif


