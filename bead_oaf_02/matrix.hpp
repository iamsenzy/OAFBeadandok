//
//  matrix.hpp
//  bead_oaf_02
//
//  Created by Geszti Bence on 2015. 10. 13..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp
#include <iostream>

struct Node{
    int value,place;
    Node *next;
    
    Node(int k=0 ,int a=0, Node* p=NULL):
    place(k),value(a), next(p) {}
};

class Matrix
{
public:
    enum Exeptions{OVERINDEX};
    Matrix(int n);
    ~Matrix();
    
    bool isDiagon();
    
    void operator() (const int &row, const int &column, const int &a) throw (Exeptions);
    const int operator() (const int &row, const int &column) throw (Exeptions);
    friend std::ostream& operator << (std::ostream& s, const Matrix& matrix);
    
private:
    
    int size;
    Node *_row, *_column;
    
    void addElement(const int &row, const int &column, const int &a);
    void removeElement(const int &row, const int &column);
    
    
};


#endif /* matrix_hpp */
