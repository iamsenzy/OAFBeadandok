#include "Jatekos.h"
#include <iostream>

using namespace std;


Jatekos::Jatekos(string name)
{
    this->name = name;
    credit = 10000;
    alive = true;
    position = -1;
}

bool Moho::isBuying(int priceArg)
{
    return Jatekos::credit >= priceArg;
}

bool Ovatos::isBuying(int priceArg)
{
    return Jatekos::credit / 2 >= priceArg;
}

bool Taktikus::isBuying(int priceArg)
{
    bought = !bought;
    return bought && Jatekos::credit >= priceArg;
}
 