//
//  UgyfelEnor.hpp
//  fourthoaf
//
//  Created by Geszti Bence on 2015. 12. 03..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#ifndef UgyfelEnor_h
#define UgyfelEnor_h

#include <stdio.h>
#include <iostream>
#include "lib/enumerator.hpp"
#include "lib/seqinfileenumerator.hpp"
#include "UgyfelSummation.h"

class UgyfelEnor : public Enumerator<Ugyfel>
{
protected:
    SeqInFileEnumerator<Ugyfel> *seqenor;
    Ugyfel _current;
    bool vege;
    
public:
    UgyfelEnor(const std::string &nev)
    {
        try
        {
            seqenor = new SeqInFileEnumerator<Ugyfel>(nev);
        }
        catch (SeqInFileEnumerator<std::string>::Exceptions ex)
        {
            std::cout << "Hibas inputfile!\n";
            return;
        }
    }
    ~UgyfelEnor() { delete seqenor; }
    void First();
    void Next();
    bool End() const { return vege; }
    Ugyfel Current() const { return _current; }
    
};
#endif /* UgyfelEnor_hpp */
