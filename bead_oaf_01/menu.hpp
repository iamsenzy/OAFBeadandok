//
//  menu.hpp
//  bead
//
//  Created by Geszti Bence on 2015. 09. 24..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#ifndef menu_hpp
#define menu_hpp
#include "zsak.h"
#include <stdio.h>

class menu{
public:
    menu(){a.meretez(5);}
    void run();
    
private:
    zsak a;
    void menuszoveg();
    void berak();
    void kivesz();
    void darabszam();
    void ures();
    void unio();
    void kiir();
    void meretez();
    
    
    
};

#endif /* menu_hpp */
