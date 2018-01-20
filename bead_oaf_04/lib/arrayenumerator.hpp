#ifndef _ARRAYENUMERATOR_
#define _ARRAYENUMERATOR_

#include "enumerator.hpp"

template <typename Item>
class ArrayEnumerator : public Enumerator<Item> 
{
protected:
std::vector<Item> *vect;
int   ind;

public:
ArrayEnumerator(std::vector<Item> *v):vect(v){}

void First()        { ind = 0;}
void Next()         { ++ind;}
bool End()    const { return ind>=(int)vect->size();}
Item Current()const { return (*vect)[ind];}
};


#endif
