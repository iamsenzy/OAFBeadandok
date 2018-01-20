#ifndef JATEKOS_H
#define JATEKOS_H
#include <iostream>

using namespace std;

class Jatekos
{
    public:
        Jatekos(string name);

        void setCredit(int credit)      {this->credit = credit;}
        void setPosition(int position)  {this->position = position;}
        void setAlive(bool alive)       {this->alive = alive;}

//        void action(Mezo* &mezoArg, int playerArg);

        string  getName()       {return name;}
        int     getCredit()     {return credit;}
        int     getPosition()   {return position;}
        bool    isAlive()       {return alive;}

        virtual bool isBuying(int priceArg) {return true;}

    protected:
        string  name;
        int     credit;
        int     position;
        bool    alive;
    private:
};

class Moho:public Jatekos{
    public:
        Moho(string name):Jatekos(name){}
        bool isBuying(int priceArg);

};

class Ovatos:public Jatekos{ 
    public:
        Ovatos(string name):Jatekos(name){}
        bool isBuying(int priceArg);
};

class Taktikus:public Jatekos{
    public:
        Taktikus(string name):Jatekos(name){bought = false;}
        bool isBuying(int priceArg);
    private:
        bool bought;
};

#endif // JATEKOS_H

