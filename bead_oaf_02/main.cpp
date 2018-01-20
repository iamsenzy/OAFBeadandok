//
//  main.cpp
//  bead_oaf_02
//
//  Created by Geszti Bence on 2015. 10. 13..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#include "matrix.hpp"
#include <iostream>

class menu {
public:
    void run();
private:
    void write();
};


int main(int argc, const char * argv[]) {
    
    menu m;
    m.run();
    
    return 0;
}

void menu::run()
{
    std::cout<<"Matrix letrehozasa adja meg n-t :";
    int n;
    std::cin>>n;
    Matrix matrix(n);
    std::cout<<"Matrix letre lett hozva\n";
    int x=0;
    write();
    do{
        std::cout << "Menupont valasztas: ";
        std::cin >>x;
        switch (x) {
            case 1:
                int i, j, a;
                std::cout<<"sor: ";
                std::cin>>i;
                std::cout << "oszlop: ";
                std::cin>>j;
                std::cout<<"ertek: ";
                std::cin>>a;
                
                try {
                    matrix(i, j, a);
                } catch (Matrix::Exeptions e) {
                    if(e == Matrix::OVERINDEX)
                    {
                        std::cout<<"Hibas index!\n";
                        break;
                    }
                }
                std::cout<<"Modositas megtorten.\n";
                
                    ;  break;
                
            case 2:
                
                std::cout<<"sor: ";
                std::cin>>i;
                std::cout << "oszlop: ";
                std::cin>>j;
                
                try {
                    std::cout << "(" << i << "," << j
                    << "): "
                    << matrix(i, j) << "\n" << std::endl;
                } catch (Matrix::Exeptions e) {
                    if(e == Matrix::OVERINDEX)
                    {
                        std::cout<<"Hibas index!\n";
                        break;
                    }
                }
                    ;  break;
            case 3: std::cout<<matrix; ;  break;
            case 4: if(matrix.isDiagon()) std::cout<<"Diagonalis.\n";
                    else std::cout<<"Nem Diagonalis.\n";
                
                    ;  break;
        }
        std::cout<< std::endl;
    }while (x!=5) ;
}

void menu::write()
{
    std::cout << "1. Elem modositasa.\n";
    std::cout << "2. Elem kiirasa.\n";
    std::cout << "3. Matrix kiirasa.\n";
    std::cout << "4. Diagonalis?.\n";
    std::cout << "5. Kilep.\n";
    
    
}

