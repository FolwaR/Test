#ifndef _TV_H_
#define _TV_H_

class Tv
{
    public:   
    enum { ON, OFF };
    enum { minVal, maxVal = 20 };
    enum { Antena, Kabel };
    enum { TV, DVD };


    friend class Remote;
    Tv(int s = OFF, int mc = 125) : state(s), volume(5), maxchanel(mc), chanel(2), mode(Kabel), input(TV) {}
    void onoff() { state ^= 1; }
    bool isOn() const { return state == ON; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() { mode ^= 1; }    
    void set_input() { input ^= 1; }
    void settings() const;

    private:
    int state;
    int volume;
    int maxchanel;
    int chanel;
    int mode;
    int input;
};


class Remote 
{
    private:
    int mode;

    public:
    Remote(int m = Tv::TV) : mode(m) {}
    bool volup(Tv & t) { return t.volup(); }
    bool voldown(Tv & t) { return t.voldown(); }
    void onoff(Tv & t) { t.onoff(); }
    void chanup(Tv & t) { t.chanup(); }
    void chandown(Tv & t) { t.chandown(); }
    void set_chan(Tv & t, int c) { t.chanel = c ;}
    void set_mode(Tv & t) { t.set_mode(); }
    void set_inpu(Tv & t) { t.set_input(); }
};




#endif
