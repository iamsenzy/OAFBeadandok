//
//  zsak.cpp
//  bead
//
//  Created by Geszti Bence on 2015. 09. 24..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#include "zsak.h"

zsak::zsak(int n)
{
    _meret=n;
    _t = new int[n];
    _darab = 0;
    for (int i=0;i<_meret;++i){
        _t[i]=0;
    }
}


zsak::zsak(const zsak &s)
{
    _meret=s._meret;
    _darab=s._darab;
    _t= new int[_meret];
    for (int i=0; i<_meret; i++) {
        _t[i]=s._t[i];
    }
}
zsak& zsak::operator=(const zsak &s)
{
    if (this!=&s){
        delete[] _t;
        _meret=s._meret;
        _darab=s._darab;
        _t= new int[_meret];
        for (int i=0; i<_meret; i++) {
            _t[i]=s._t[i];
        }

    }
    return* this;
}

int zsak::db(const int &s)
{
    int db = 0;
    for(int i=0;i<_meret;++i){
        if(_t[i]==s) db++;
    }
    return db;
}



void zsak::be(const int &s)
{
    if(_darab==_meret) throw TELI;
    else {
        _t[_darab]=s;
        _darab++;
    }
}


void zsak::ki(const int &s)
{
    bool l = false;
    int ind = 0;
    int i = 0;
    while(!l && i<_darab){
        l = _t[i] == s;
        ind = i;
        i++;
    }
    if(l){
        _darab--;
        _t[ind] = _t[_darab];
        _t[_darab] = 0;
    }
    else throw NINCS;
}

void zsak::meretez(const int &new_s)
{
    if (new_s==_meret) return;
    int* new_t =new int[new_s];
    if (new_s>_meret) {
        for (int i=0; i<_meret; i++) {
            new_t[i]=_t[i];
        }
        
        for (int i=_meret; i<new_s; i++) {
            new_t[i]=0;
        }
    }
    else
    {
        for (int i=0; i<new_s; i++) {
            new_t[i]=_t[i];
        }
        _darab=new_s;
    }
    
    delete[] _t;
    _t=new_t;
    _meret=new_s;
}


std::istream& operator>>(std::istream& s, zsak& a)
{
    std::cout << std::endl;
    int ertek;
    for(int i=0; i<a._meret; ++i) {
        std::cout << i+1 << ". elem = ";
        s >> ertek;
        try{
            a.be(ertek);
        }catch(zsak::Exceptions ex){
            if(ex==zsak::TELI) std::cout << "A zsak tele van!" << std::endl;
        }
    }
    return s;
}

std::ostream& operator<<(std::ostream& s,const zsak& a)
{
    for(int i=0; i<a._darab; ++i){
        s << i+1 << ".elem: " << a._t[i] << std::endl;
    }
    return s;
}

zsak operator+(const zsak& a, const zsak& b)
{
    zsak c(a._darab+b._darab);
    for(int i=0;i<a._darab;++i){
        c._t[i]=a._t[i];
    }
    for(int i=0;i<b._darab;++i){
        c._t[i+a._darab]=b._t[i];
    }
    c._darab=a._darab+b._darab;
    return c;
}