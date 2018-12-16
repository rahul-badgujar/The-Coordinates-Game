#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Coordinate.h"

using std::string;

class Player
{
    public:
        Player();
        virtual ~Player();

        string getName();
        void setName(string);
        unsigned int getWins();
        Player operator ++ (int);
        Coordinate& getSecreteCoord();
        Coordinate& getMoveCoord();
        void setSecretCoord(const Coordinate& c);
        void setMoveCoord(const Coordinate& c);

    protected:

    private:
        string name;
        unsigned int wins;
        Coordinate secretCoordinate;
        Coordinate moveCoordinate;

};

#endif // PLAYER_H
