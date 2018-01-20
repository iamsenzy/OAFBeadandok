//
//  main.cpp
//  fourthoaf
//
//  Created by Geszti Bence on 2015. 12. 03..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

#include "Ugyfel.h"
#include "UgyfelEnor.h"



using namespace std;


int main()
{
    UgyfelEnor inF("/Minden/egyetem/OAF/beadandoim/bead_oaf_04/fourthoaf/in.txt");

    for (inF.First(); !inF.End(); inF.Next()) {
        cout<<inF.Current().bank<<" "<<inF.Current().ossz<<endl;
    }
  
    return 0;
}
