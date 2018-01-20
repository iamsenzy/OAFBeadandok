#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Mezo.h"
#include "Jatekos.h"
using namespace std;

class Game
{
    public:
        Game();
        ~Game();

        void run();
        void nextTurn();
        void action(Mezo* &m, Jatekos* &p);
        void out(Jatekos* &p);

    private:
        void write();

        vector <Mezo*> Table;
        vector <Jatekos*> Players;
        vector <int> Dobasok;
        int dead;
        int j;
        int m;
        int dob;

};

#endif // GAME_H
