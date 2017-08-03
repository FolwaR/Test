//Szablony jako składowe


#ifndef _BETA_H_
#define _BETA_H_

#include <iostream>

using namespace std;

template <typename T>
class beta
{
	
	private:
	
	template <typename V>
	class hold
	{
		private:	
		V val;
		public:
		hold(V v = 0) : val(v) {};
		void show() const { cout << val <<endl; }
		V value() const { return val; }
	};	

	hold<T> q;
	hold<int> n;
	
	public:
		
	beta(T t = 0, int i = 0) : q(t), n(i) {}

	template <typename U>
	U blab(U u, T t) { return (n.value()  + q.value()) * u / t; }
	
	void show() const { q.show(); n.show();}
};






#endif

