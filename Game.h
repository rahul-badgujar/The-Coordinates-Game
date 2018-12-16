#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
#include <conio.h>

#include "Coordinate.h"
#include "Player.h"

#define CLEAR system("cls")
#define PAUSE cout<<endl; system("pause");

using namespace std;

enum class GameStates{PLAY,EXIT,CREDITS,HTP};

class Game
{
    public:
        Game();
        virtual ~Game();

        void run();

    protected:

    private:
        GameStates gameState;
        GameStates mainMenu();
        void startGame();
        void rulesScreen();
        void creditsScreen();

        template <typename T>
        void input(T&,string);
        void inputCoords(Coordinate& c,string nm);
        template <typename P,typename Q>
        void input(P&,Q&,string);
        Player p1;
        Player p2;

};

#endif // GAME_H
