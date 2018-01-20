//
//  UgyfelSummation.hpp
//  fourthoaf
//
//  Created by Geszti Bence on 2015. 12. 03..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#ifndef UgyfelSummation_h
#define UgyfelSummation_h

#include "Ugyfel.h"
#include "lib/summation.hpp"
#include <stdio.h>

class UgyfelSummation : public Summation<Ugyfel,Ugyfel> //szummázza az egyes diákok jegyeit
{
public:
    UgyfelSummation(const Ugyfel &x) : Summation<Ugyfel,Ugyfel>(), ugyfel(x) {}
protected:
    Ugyfel ugyfel;
    void Init() //inicializalas
    {
        result->bank = ugyfel.bank;
        result->ossz = 0;
    }
    void First() {}
    bool WhileCond(const Ugyfel &x) const { return x.bank == ugyfel.bank; } //feltetelig dolgozik
    void Add(const Ugyfel &x); //ciklusmag
    
};
#endif /* UgyfelSummation_hpp */
