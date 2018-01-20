//
//  Ugyfel.cpp
//  fourthoaf
//
//  Created by Geszti Bence on 2015. 12. 03..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#include "Ugyfel.h"
#include <iostream>

std::istream& operator>>(std::istream& f, Ugyfel &x)
{
    f >> x.bank >> x.ossz;
    return f;
}