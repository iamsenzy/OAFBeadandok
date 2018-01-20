//
//  UgyfelEnor.cpp
//  fourthoaf
//
//  Created by Geszti Bence on 2015. 12. 03..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#include "UgyfelEnor.h"
#include "UgyfelSummation.h"
#include <iostream>
//!ISTREAM

void UgyfelEnor::First()
{
    seqenor->First();
    Next();
}

void UgyfelEnor::Next()
{
    
    vege = seqenor->End();
    if (vege) return;
    _current = seqenor->Current();
    UgyfelSummation sum(_current);
    sum.AddEnumerator(seqenor);
    sum.Run();
    _current = sum.Result();
}
