// stonewt.h -- definicja klasy Stonewt
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
    private:
		static const int Lbs_per_stn = 14;
        int stone;               // masa w ca�ych kamieniach
        double pds_left;         // reszta w funtach
        double pounds;           // masa w funtach
    public:
        Stonewt(double lbs);          // konstruktor dla funt�w
        Stonewt(int stn, double lbs); // konstruktor dla kamieni i funt�w
        Stonewt();                    // konstruktor domy�lny
        ~Stonewt();
        void show_lbs() const; // wy�wietla mas� w funtach
        void show_stn() const; // wy�wietla mas� w kamieniach
};
#endif

