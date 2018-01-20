//
//  menu.cpp
//  bead
//
//  Created by Geszti Bence on 2015. 09. 24..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#include "menu.hpp"
#include "zsak.h"
#include <iostream>

void menu::run()
{
    int x=0;
    menuszoveg();
    do{
        std::cout << "Menupont valasztas: ";
        std::cin >>x;
       switch (x) {
            case 1:   berak();  break;
            case 2:   kivesz();  break;
            case 3:   darabszam();  break;
            case 4:   ures();  break;
            case 5:   unio();  break;
            case 6:   kiir();  break;
            case 7:   meretez(); break;
            }
        std::cout<< std::endl;
    }while (x!=0) ;
}

void menu::menuszoveg()
{
    std::cout << "1. Elem berakasa.\n";
    std::cout << "2. Elem kivetele.\n";
    std::cout << "3. Elem darabszama.\n";
    std::cout << "4. Ures a zsak?.\n";
    std::cout << "5. Unio.\n";
    std::cout << "6. Zsak kiirasa.\n";
    std::cout << "0. Kilep.\n";
    
}

void menu::berak()
{
    int n;
    std::cout << "Elem: ";
    std::cin >>n;
    try {
        a.be(n);
    } catch (zsak::Exceptions ex) {
        if (ex==zsak::TELI) {
            std::cout<< "A zsak tele van."<< std::endl;;
        }
    }
 
    
}

void menu::kivesz()
{
    int n;
    std::cout << "Elem: ";
    std::cin >>n;
    try {
        a.ki(n);
    } catch (zsak::Exceptions ex) {
        if (ex==zsak::NINCS) {
            std::cout<<"Nincs a zsakban ilyen elem."<< std::endl;;
        }
    }
}

void menu::darabszam()
{
    int n;
    std::cout << "Elem: ";
    std::cin >>n;
    std::cout << a.db(n)<<" darab ilyen szam van a zsakban"<< std::endl;;
}

void menu::ures()
{
    if (a.ures()) {
        std::cout << "Üres."<< std::endl;;
    }
    else
    {
        std::cout<< "Nem üres."<< std::endl;;
    }
}

void menu::kiir()
{
    if (a.ures()) {
        std::cout<<"A zsak ures"<< std::endl;
    }
    else{
    std::cout <<"A zsak elemei: "<< std::endl << a << std::endl;
    }
}

void menu::unio()
{
    zsak b(5);
    std::cout << "Uj zsak elemei: "<< std::endl;
    std::cin >> b;
    std::cout << "Elso zsak elemei:" << a<< std::endl;
    std::cout << "Ket zsak unioja: " << std::endl << a + b;
}

void menu::meretez()
{
    int n;
    std::cout << "Uj meret: ";
    std::cin >>n;
    std::cout<< std::endl;
    a.meretez(n);
}
