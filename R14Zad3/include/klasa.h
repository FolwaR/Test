#include <iostream>

using std::string;


class Worker
{
    private:
		string fullname;
		long id;
       
    protected:
		virtual void Get();
		virtual void Data() const;

	public:
		Worker() : fullname("noName"), id(0.0)	{}
		Worker(const string & n, long i) : fullname(n), id(i) {}
		virtual ~Worker() {} ;
		virtual void Set() = 0;
		virtual void Show() const = 0;
};


class Waiter : virtual public Worker
{
	private:
		int panche;	

	protected:
		void Get();
		void Data() const;
    
	public:
		Waiter() : Worker(), panche(0) {}
		Waiter(int pa, const string & n, long i) : Worker(n,i), panche(pa) {}
		Waiter(const Worker & w, int pa = 0) : Worker(w), panche(pa) {}
		~Waiter() {};
	 
		void Set();
		void Show() const;
};


class Singer : virtual public Worker
{
 	protected:
		void Get();
		void Data() const;


	protected:
		enum { inny, alt, kontralt, sopran, bas, baryton, tenor };
		enum { Vtypes = 7 };
	private:
		static const char *pv[Vtypes];
        int tone;
   

    public:
        Singer() : Worker(), tone(inny) {}
        Singer(const string & n, long i, int tn = inny) : Worker(n,i), tone(tn) {}
        Singer(const Worker & w, int tn = inny) : Worker(w), tone(tn) {}
        ~Singer() {};

        void Set();
        void Show() const;
};


class SingerWaiter : public Singer, public Waiter
{
	protected:
		void Get();
		void Data() const;

	public:
		SingerWaiter() {};
		SingerWaiter(const string &s, long n, int p = 0, int v = inny):Worker(s,n),Waiter(p,s,n), Singer(s,n,v) {}
		SingerWaiter(const Worker & wk, int p = 0, int v = inny): Worker(wk), Waiter(wk,p), Singer(wk, v) {}
		SingerWaiter(const Waiter & wk, int v = inny) : Worker(wk), Waiter(wk), Singer(wk,v) {}
		SingerWaiter(const Singer & si, int p = 0) : Worker(si), Waiter(si, p), Singer(si) {}
	
		void Set();
		void Show() const;

};

