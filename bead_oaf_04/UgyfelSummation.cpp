//
//  UgyfelSummation.cpp
//  fourthoaf
//
//  Created by Geszti Bence on 2015. 12. 03..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#include "UgyfelSummation.h"
void UgyfelSummation::Add(const Ugyfel &x)
{
    result->bank = ugyfel.bank;
    result->ossz += x.ossz;
}