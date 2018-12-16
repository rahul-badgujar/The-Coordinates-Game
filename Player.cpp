#include "Player.h"

Player::Player():name("NA"),wins(0)
{
    //ctor
}

Player::~Player()
{
    //dtor
}

Player Player::operator ++ (int)
{
    this->wins++;
    return *this;
}

string Player::getName()
{
    return name;
}
void Player::setName(string nm)
{
    name=nm;
}
unsigned int Player::getWins()
{
    return wins;
}

Coordinate& Player::getSecreteCoord()
{
    return secretCoordinate;
}
Coordinate& Player::getMoveCoord()
{
    return moveCoordinate;
}
void Player::setSecretCoord(const Coordinate& c)
{
    secretCoordinate=c;
}
void Player::setMoveCoord(const Coordinate& c)
{
    moveCoordinate=c;
}
