#ifndef COORDINATE_H
#define COORDINATE_H

#include <math.h>


class Coordinate
{
    public:
        Coordinate();
        virtual ~Coordinate();
        Coordinate& operator=(const Coordinate&);
        double operator - (const Coordinate&);
        bool operator == (const Coordinate&);

        int getX();
        int getY();
        void setCoordinates(int x,int y);

    protected:

    private:
        int X;
        int Y;
};

#endif // COORDINATE_H
