#ifndef MEZO_H
#define MEZO_H
#include "Jatekos.h"

class Mezo
{
    public:
        Mezo(int n);

        void setPrice(int price)        {this->price = price;}
        void setOwner(Jatekos* owner)   {this->owner = owner;}
        void setHouse(bool house)       {this->house = house;}

        int         getType()   {return type;}
        Jatekos*    getOwner()  {return owner;}
        int         getPrice()  {return price;}
        bool        getHouse()  {return house;}

    protected:
        int type;
        int price;
        Jatekos* owner;
        bool house;

};
class Ingatlan:public Mezo{
    public:
        Ingatlan():Mezo(1){price = 1000;}
};

class Szolgaltatas:public Mezo{
    public:
        Szolgaltatas(int price):Mezo(2){this->price = price;}
};

class Szerencse:public Mezo{
    public:
        Szerencse(int price):Mezo(3){this->price = price;}
};

#endif // MEZO_H
 
