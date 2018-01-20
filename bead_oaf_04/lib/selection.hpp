#ifndef _SELECTION_
#define _SELECTION_

#include "procedure.hpp"

template < typename Item >
class Selection : public Procedure<Item> {
   protected:
      virtual bool Cond(const Item& e) const = 0;
      void Init() {}
      void Do(const Item& e) {}
      bool LoopCond() const { return !Cond(Procedure<Item>::enor->Current());}
   public:
      Item Elem() const { return Procedure<Item>::enor->Current();}
};

#endif
