#include <cstring>


////////////////////////////////////////////////////////

template <typename A, typename B>
class Pair_tab
{
    private:
    
    static int ile_sztuk;
    A * el_a;
    B * el_b;

    int rocznikow;
    
    public:
    Pair_tab() : el_a(nullptr), el_b(nullptr), rocznikow(0) {}; 
    Pair_tab(const A *, const B *, int r_no = 0);
    Pair_tab(const Pair_tab &);
    ~Pair_tab();
    void show() const;
    B sum_b() const;
    int ile() const;
    Pair_tab & operator=(const Pair_tab &);

};

////////////////////////////////////////////////////////

class Wino
{
    private:
    Pair_tab<int, int> wino_ile;
    char nazwa[20];
    int roczn;

    public:
    Wino() : wino_ile(nullptr, nullptr, 0) {strcpy(nazwa, "noName"); roczn = 0;}
    Wino(const char * name, int ile, int * rocznikow, int * sztuk) : wino_ile(rocznikow, sztuk, ile) {strncpy(nazwa, name, 19); nazwa[19] = '\0';} 
    Wino(const Wino &);
    ~Wino();
    
    Wino & operator=(const Wino &);    

    void show() const;

};



////////////////////////////////////////////////////////

template <typename A, typename B>
int Pair_tab<A,B>::ile() const
{
    return ile_sztuk;
}

////////////////////////////////////////////////////////

template <typename A, typename B>
int Pair_tab<A,B>::ile_sztuk = 0;

////////////////////////////////////////////////////////

template <typename A, typename B>
Pair_tab<A,B>::Pair_tab(const Pair_tab & p)
{
    el_a = new A [p.rocznikow];
    el_b = new B [p.rocznikow];

        
    for (int i = 0; i < p.rocznikow; i++)
    {
        el_a[i] = p.el_a[i]; 
        el_b[i] = p.el_b[i];
    }
    
    rocznikow = p.rocznikow;
    ile_sztuk++;
}

////////////////////////////////////////////////////////

template <typename A, typename B>
Pair_tab<A,B> & Pair_tab<A,B>::operator=(const Pair_tab & p)
{
    if (this == &p)
        return *this;
    
    else
    {

        if (el_a != nullptr || el_b != nullptr)
        {
            delete [] el_a;
            delete [] el_b;
        }

        el_a = new A [p.rocznikow];
        el_b = new B [p.rocznikow];


        for (int i = 0; i < p.rocznikow; i++)
        {
            el_a[i] = p.el_a[i];
            el_b[i] = p.el_b[i];
        }

        rocznikow = p.rocznikow;  
      
        return *this;
    
    }
}

////////////////////////////////////////////////////////

template <typename A, typename B>
Pair_tab<A,B>::~Pair_tab()
{
    delete [] el_a;
    delete [] el_b; 
    ile_sztuk--;
}

////////////////////////////////////////////////////////

template <typename A, typename B>
Pair_tab<A,B>::Pair_tab(const A * tab_rocz, const B * tb_szt, int r_no)
{
    ile_sztuk++;
    el_a = new A [r_no];
    el_b = new B [r_no];
    rocznikow = r_no;

    for (int i = 0; i < r_no; i++)
    {
        el_a[i] = tab_rocz[i];
        el_b[i] = tb_szt[i];
    }
}

////////////////////////////////////////////////////////

template <typename A, typename B>
void Pair_tab<A,B>::show() const
{
    std::cout << "\tRocznik:\tButelki:\n";
    for (int i = 0; i < rocznikow; i++)
    {
        std::cout << '\t' << el_a[i] <<"\t\t" << el_b[i] << std::endl;
    }
}

////////////////////////////////////////////////////////

template <typename A, typename B>
B Pair_tab<A,B>::sum_b() const
{
    B sum = 0;
    
    for (int i = 0; i < rocznikow; i++)
        sum += el_b[i];

    return sum;
}

////////////////////////////////////////////////////////

////////////////////////////////////////////////////////

void Wino::show() const
{  
    std::cout << nazwa <<std::endl;
    wino_ile.show();
    std::cout << "Suma butelek: " <<wino_ile.sum_b();
    std::cout << std::endl;
}

////////////////////////////////////////////////////////

Wino::Wino(const Wino & w)
{
    wino_ile = w.wino_ile;
    strncpy(nazwa, w.nazwa, 19);
    nazwa[19] = '\0';
}





Wino & Wino::operator=(const Wino & w)
{
    if (this == &w)
        return *this;

    else
    {
        wino_ile = w.wino_ile;
        strncpy(nazwa, w.nazwa, 19);
        nazwa[19] = '\0';
        return *this;
    }
}



Wino::~Wino()
{
    wino_ile.~Pair_tab(); 
}



