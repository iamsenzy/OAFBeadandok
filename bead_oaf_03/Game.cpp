#include "Game.h"
#include <iostream>
#include <fstream>
using namespace std;

Game::Game()
{

    ifstream f("/Users/gesztibence/Desktop/Capitaly/Capitaly/test.txt");
    f >> m;
    for(int i=0; i<m; i++)
    {
        int t;
        int ar;
        f >> t;
        switch(t)
        {
            case 1:Table.push_back(new Ingatlan()); break;
            case 2:
                f >> ar;
                Table.push_back(new Szolgaltatas(ar)); break;
            case 3:
                f >> ar;
                Table.push_back(new Szerencse(ar)); break;
        }
    }
    f >> j;
    for(int i=0; i<j; i++)
    {
        char t;
        string nev;
        f >> nev;
        f >> t;
        switch(t)
        {
            case 'm': Players.push_back(new Moho(nev)); break;
            case 'o': Players.push_back(new Ovatos(nev)); break;
            case 't': Players.push_back(new Taktikus(nev)); break;
        }
    }
    int n;
    f >> n;
    while (!f.eof())
    {
        Dobasok.push_back(n);
        f >> n;
    }
    f.close();
    dob = 0;
    dead = 0;
}

Game::~Game()
{
    for(int i=0; i<j; i++){
        delete Players[i];
    }
    for(int i=0; i<m; i++){
        delete Table[i];
    }
}

void Game::run()
{
    cout << "Kezdetbe: \n";
    write();
    while(dead < j-1 && dob < Dobasok.size()){
        nextTurn();
        write();
    }
}

void Game::nextTurn()
{
    for(int i=0; i<j && dob < Dobasok.size(); i++){
        if(Players[i]->isAlive()){
            Players[i]->setPosition((Players[i]->getPosition()+Dobasok[dob])%m);
            action(Table[Players[i]->getPosition()], Players[i]);
            if(!Players[i]->isAlive())
                out(Players[i]);
            dob++;
        }
    }
}

void Game::out(Jatekos* &p)
{
    for(int i=0; i<m; i++){
        if(Table[i]->getOwner()==p){
            Table[i]->setOwner(NULL);
            Table[i]->setHouse(false);
            Table[i]->setPrice(1000);
        }
    }
    p->setPosition(-1);
    p->setCredit(0);
    dead++;
}

void Game::action(Mezo* &mezoArg, Jatekos* &playerArg)
{
    switch(mezoArg->getType())
    {
        case 1: //ingatlan
            if(mezoArg->getOwner() == NULL && playerArg->isBuying(mezoArg->getPrice())) //nincs tulajdonos
            {
                mezoArg->setOwner(playerArg);
                playerArg->setCredit(playerArg->getCredit() - mezoArg->getPrice());
                mezoArg->setPrice(500);
            }
            else if(mezoArg->getOwner() == playerArg && !mezoArg->getHouse() && playerArg->isBuying(4000)) //ha a jatekose, es hazat venne ra
            {
                mezoArg->setHouse(true);
                playerArg->setCredit(playerArg->getCredit() - 4000);
                mezoArg->setPrice(2000);
            }
            else if(mezoArg->getOwner() != playerArg && mezoArg->getOwner() != NULL) //ha mar egy masik jatekose
            {
                //adott jatekostol levonom a mezo arat
                playerArg->setCredit(playerArg->getCredit() - mezoArg->getPrice());
                playerArg->setAlive(playerArg->getCredit() >= 0);
                //mezo tulajanak jovairom
                mezoArg->getOwner()->setCredit(mezoArg->getOwner()->getCredit() + mezoArg->getPrice());
            }
            break;

        case 2: //szolgaltatas
            playerArg->setCredit(playerArg->getCredit() - mezoArg->getPrice());
            playerArg->setAlive(playerArg->getCredit() >= 0);
            break;

        case 3: //szerncse
            playerArg->setCredit(playerArg->getCredit() + mezoArg->getPrice());
            break;
    }
}

void Game::write()
{

       //Jatekosok tulajdonait, vagyonat írja ki
       for(int i=0; i<j; i++){
	   cout << Players[i]->getName() <<" penze: "<<Players[i]->getCredit()<<endl;
           cout << "Birtokolt mezoi: ";
           for(int k=0; k<m; k++){
              if (Table[k]->getOwner()==Players[i]) cout << k << ". ";
           }
           cout << endl<< endl;
       }
    cout <<"________________________________________________________________________\n\n";
}
