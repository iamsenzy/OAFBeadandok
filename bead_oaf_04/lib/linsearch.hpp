#ifndef _LINSEARCH_
#define _LINSEARCH_

#include "procedure.hpp"

#include <iostream>

template < typename Item, bool optimist = false >
class LinSearch : public Procedure<Item> {
   protected:
      bool l;
      Item elem;

      void Init() { l = optimist; }
      void Do(const Item& e) { l = Cond(elem = e); }

      virtual bool Cond(const Item& e) const = 0;
      bool LoopCond() const { return (optimist?l:!l) && Procedure<Item>::LoopCond();}

   public:
      bool Found()  const { return l;}
      Item Elem()   const { return elem;}
};

#endif
