//
//  Ugyfel.hpp
//  fourthoaf
//
//  Created by Geszti Bence on 2015. 12. 03..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#ifndef Ugyfel_h
#define Ugyfel_h

#include <stdio.h>
#include <string>

struct Ugyfel
{
    std::string bank;
    int ossz;
    
    
    Ugyfel (std::string _bank="", int _ossz=0)
    {
        bank = _bank;
        ossz = _ossz;
        
    }
    
    friend std::istream& operator>>(std::istream& f, Ugyfel &x);
};


#endif /* Ugyfel_hpp */
