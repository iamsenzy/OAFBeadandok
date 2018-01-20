//
//  zsak.h
//  bead
//
//  Created by Geszti Bence on 2015. 09. 24..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#ifndef zsak_h
#define zsak_h
#include <iostream>
class zsak{
    
public:
    enum Exceptions{TELI,NINCS};
    zsak(int n=0);
    ~zsak(){delete[] _t;}
    zsak(const zsak &s);
    zsak& operator= (const zsak &s);
    void be(const int &s);
    void ki(const int &s);
    bool ures() {return _darab==0;}
    int db(const int &s);
    void meretez(const int &new_s);
    friend std::istream& operator>>(std::istream& s, zsak& a);
    friend std::ostream& operator<<(std::ostream& s, const zsak& a);
    friend zsak operator+ (const zsak& a, const zsak& b);
private:
    int* _t;
    int _meret;
    int _darab;
    
};



#endif /* zsak_h */
