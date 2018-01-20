#ifndef _MAXSEARCH_
#define _MAXSEARCH_

#include "procedure.hpp"


template <typename Value> // Value implementálja: operator<, operator>
class Greater{
    public:
        bool operator()(const Value& l, const Value& r){
            return l > r;
        }
};

template <typename Value> // Value implementálja: operator<, operator>
class Less{
    public:
        bool operator()(const Value& l, const Value& r){
            return l < r;
        }
};

template <typename Item, typename Value = Item, typename Compare = Greater<Value> >
class MaxSearch : public Procedure<Item>
{
    protected:
        bool    l;
        Item    optelem;
        Value   opt;
        Compare better;

        void Init(){ l = false;}
        void Do(const Item& current);

        virtual Value Func(const Item& e) const = 0;
        virtual bool  Cond(const Item& e) const { return true;}

    public:
        bool Found()   const { return l;}
        Value Opt() const { return opt;}
        Item OptElem() const { return optelem;}
};

template <class Item, class Value, class Compare>
void MaxSearch<Item,Value,Compare>::Do(const Item& current)
{
    Value val = Func(current);
    if ( !Cond(current) ) return;
    if (l){
        if (better(val,opt)){
            opt = val;
            optelem = current;
        }
    }
    else {
        l = true;
        opt = val;
        optelem = current;
    }
}

#endif
