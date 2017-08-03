#include <iostream>

using std::string;


class Worker
{
	protected:
		virtual void Get();
		virtual void Data();

	private:
		string fullname;
		long id;
	public:
		Worker() : fullname("noName"), id(0.0)	{}
		Worker(const string & n, long i) : fullname(n), id(i) {}
		virtual ~Worker() {} = 0;
		virtual void Set() = 0;
		virtual void Show() const = 0;

};


class Waiter : virtual public Worker
{
	protected:
		virtual void Get();
		virtual void Data();


	private:
		int panche;	
	public:
		Waiter() : Worker(), panche(0) {}
		Waiter(int pa, const string & n, long i) : Worker(n,i), panche(pa) {}
		Waiter(Worker & w, int pa = 0) : Worker(w), panche(pa) {}
		virtual ~Waiter() {};
	 
		virtual void Set();
		virtual void Show() const;

};


class Singer : virtual public Worker
{
	protected:
		virtual void Get();
		virtual void Data();


	protected:
		enum { inny, alt, kontralt, sopran, bas, baryton, tenor };
		enum { Vtypes = 7 };
	
    private:
		static char *pv[Vtypes];
        int tone;
    public:
        Singer() : Worker(), tone(inny) {}
        Singer(const string & n, long i, int tn = inny) : Worker(n,i), tone(tn) {}
        Singer(Worker & w, int tn = inny) : Worker(w), tone(tn) {}
        virtual ~Singer() {};

        virtual void Set();
        virtual void Show() const;
};


class SingerWaiter
{
	protected:
		virtual void Get();
		virtual void Data();

	public:
		SingerWaiter();
		SingerWaiter(const string &s, long n, int p = 0, int v = inna):Worker(s,n),Waiter(s,n,p), Singer(s,n,v) {}
		SingerWaiter(const Worker & wk, int p = 0, int v = inna): Worker(wk), Waiter(wk,p), Singer(wk, v) {}
		SingerWaiter(const Waiter & wk, int v = inna) : Worker(wt), Waiter(wt), Singer(wk,v) {}
		SingerWaiter(const Singer & si, int p = 0) : Worker(si), Waiter(si, p), Singer(si) {}
	
		virtual void Set();
		virtual void Show();

};

