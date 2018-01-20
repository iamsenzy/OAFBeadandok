#ifndef SUMMATION_HPP
#define SUMMATION_HPP

#include "procedure.hpp"

template < typename Item, typename ResultType = Item >
class Summation : public Procedure<Item>
{
    protected:
        ResultType *result;
        bool inref;

        Summation(){ inref = true; result = new ResultType; }
        Summation(ResultType *r){ inref = false; result = r; }
        void Init() {}
        void Do(const Item& e){ if(Cond(e)) Add(e); }
        virtual void Add(const Item& e) = 0;
        virtual bool Cond(const Item& e) const { return true;}
    public:
        ResultType Result() { return *result; }
        ~Summation(){ if(inref) delete result;}
};

#endif
