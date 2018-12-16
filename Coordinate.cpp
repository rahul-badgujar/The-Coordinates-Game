#include "Coordinate.h"

Coordinate::Coordinate():X(0),Y(0)
{
    // ctro
}

Coordinate::~Coordinate()
{
    //dtor
}

Coordinate& Coordinate::operator=(const Coordinate& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->X=rhs.X;
    this->Y=rhs.Y;
    return *this;
}
bool Coordinate::operator == (const Coordinate& rhs)
{
    if(this->X==rhs.X && this->Y==rhs.Y)
        return true;
    return false;
}

double Coordinate::operator - (const Coordinate& rhs)
{
    double distSq=fabs((this->X-rhs.X)*(this->X-rhs.X) + (this->Y-rhs.Y)*(this->Y-rhs.Y));
    return sqrt(distSq);
}

int Coordinate::getX()
{
    return X;
}
int Coordinate::getY()
{
    return Y;
}
void Coordinate::setCoordinates(int x,int y)
{
    this->X=x;  this->Y=y;
}
