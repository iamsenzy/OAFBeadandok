#ifndef _PROCEDURE_
#define _PROCEDURE_
#include <cstddef>
#include "enumerator.hpp"

template <typename Item>
class Procedure
{
    protected:
        Enumerator<Item> *enor;

        Procedure():enor(NULL){}
        virtual void Init() = 0;
        virtual void First() {enor->First();}
        virtual bool LoopCond() const
                   { return !enor->End() && WhileCond(enor->Current()) ; }
        virtual bool WhileCond(const Item& current) const { return true; }
        virtual void Do(const Item& current) = 0;

    public:
        enum Exceptions { MissingEnumerator};
        void Run();
        void AddEnumerator(Enumerator<Item>* en){ enor = en;}
        virtual ~Procedure(){}
};

template <class Item>
void Procedure<Item>::Run()
{
    if(enor==NULL) throw MissingEnumerator;
    Init();
    for(First(); LoopCond(); enor->Next()){
        Do(enor->Current());
    }
}

#endif
