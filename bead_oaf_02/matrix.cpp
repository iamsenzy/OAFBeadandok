//
//  matrix.cpp
//  bead_oaf_02
//
//  Created by Geszti Bence on 2015. 10. 13..
//  Copyright © 2015. Geszti Bence. All rights reserved.
//

#include "matrix.hpp"

Matrix::Matrix(int n)
{
    size=n;
    _row=new Node[size];
    _column=new Node[size];
    
    for (int i=0; i<size;i++)
    {
        _row[i]=Node();
        _column[i]=Node();
    }
}

Matrix::~Matrix()
{
    for (int i=0;i<size;i++)
    {
        Node* del_r=&_row[i];
        Node* del_c=&_column[i];
        del_r=del_r->next;
        del_c=del_c->next;
        while(del_r != NULL){
            Node* p= del_r;
            del_r = p->next;
            delete p;
        }
        
        while (del_c != NULL) {
            Node* p=del_c;
            del_c = p->next;
            delete p;
        }
    }
    delete[] _row;
    delete[] _column;
}

void Matrix::addElement(const int &row, const int &column, const int &a)
{
    Node* r= &_row[row-1];
    Node* c= &_column[column-1];
    
    
    if (c->next == NULL){c->next = new Node(row,a,NULL);}
    else {
        Node* check_r = &_column[column-1];
        check_r = check_r->next;
        while (check_r != NULL)
        {
            if (check_r->place > row)
            {
                c->next = new Node(row,a,c->next);
                break;
            }
            
            if (check_r->place == row)
            {
                check_r->value = a;
                break;
            }
            
            check_r = check_r->next;
            c = c->next;
        }
        if(check_r == NULL) c->next = new Node(row,a,NULL);
       
    };

    
    if (r->next == NULL){r->next = new Node(column,a,NULL);}
    else {
        Node* check_c = &_row[row-1];
        check_c = check_c->next;
        while (check_c != NULL)
        {
            if (check_c->place > column)
            {
                r->next = new Node(column,a,r->next);
                break;
            }
            if (check_c->place == column)
            {
                check_c->value = a;
                break;
            }
            check_c = check_c->next;
            r = r->next;
        }
        if(check_c == NULL) r->next = new Node(column,a,NULL);
    };
    
}


void Matrix::removeElement(const int &row, const int &column)
{
    
    Node* c = &_column[column-1];
    Node* r = &_row[row-1];
    if (r->next != NULL)
    {
        Node* check_c = &_row[row-1];
        check_c = check_c->next;
        while(check_c!=NULL)
        {
            if (check_c->place == column)
            {
                r->next = check_c->next;
                delete check_c;
                break;
            }
            check_c = check_c->next;
            r = r->next;
        }
    }
    if (c->next != NULL)
    {
        Node* check_r = &_column[column-1];
        check_r = check_r->next;
        while(check_r!=NULL)
        {
            if(check_r->place == row)
            {
                c->next = check_r->next;
                delete check_r;
                break;
            }
            check_r= check_r->next;
            c = c->next;
        }
    }

}



void Matrix::operator() (const int &row, const int &column, const int &a) throw (Exeptions)
{
    if (row>size || column>size) throw OVERINDEX;
    else
    {
        if(a==0) removeElement(row,column);
        else addElement(row, column, a);
    }
}

const int Matrix::operator()(const int&row, const int &column) throw (Exeptions)
{
    if(row > size || column > size) throw OVERINDEX;
    else
    {
        Node* p = &_row[row-1];
        while(p->next != NULL && p->place < column)
        {
            p = p->next;
            if(p->place == column) return p->value;
        }
        return 0;
    }

}

bool Matrix::isDiagon()
{
    for(int i=0;i<size;i++)
    {
        Node* p =&_row[i];
        p=p->next;
        while (p!=NULL) {
            if (p->place != i+1) return false;
            p=p->next;
        }
    }
    return true;
}

std::ostream& operator << (std::ostream& s, const  Matrix &matrix)
{
    Node* p;
    for(int i=0;i<matrix.size;i++)
    {
        p=&matrix._row[i];
        p=p->next;
        for(int j=1;j<=matrix.size;j++)
        {
            if(p==NULL || p->place>j) s<<"0\t";
            else if(p->place ==j)
            {
                s<<p->value<<"\t";
                // s<<p->place<<"\t";
                p=p->next;
            }
        }
        s<<std::endl;
    }
    
    return(s);
}