#ifndef COUNTING_HPP
#define COUNTING_HPP

#include "summation.hpp"

template < typename Item >
class Counting : public Summation<Item, int>
{
    public:
        Counting():Summation<Item,int>(){}

    protected:

        void Init()             { *Summation<Item,int>::result = 0;}
        void Add(const Item& e) { ++*Summation<Item,int>::result;}
};

#endif
