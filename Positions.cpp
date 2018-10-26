#include <iostream>
#include "Positions.h"

using namespace std;

// Sets initial value of marbles in each square.

void Positions::setSquares()
{
    for (int i = 0; i < numSquares; i++)
    {
        squares[i] = 3;
    }
}

// Retrieves value of marbles.

int Positions::getMarbles(int loc)
{
    loc = squares[loc];
    return loc;
}

// Removes marbles from square.

void Positions::emptyMarbles(int loc, int marbles)
{
    squares[loc] = squares[loc] - marbles;
}

// Increments marbles in square.

void Positions::incrementMarblesInSquare(int loc)
{
    squares[loc] = squares[loc] + 1;
}

// Sets initial value of marbles in end zone to 0.

void Positions::setEndZones()
{
    for (int i = 0; i < numEndZones; i++)
    {
        endZones[i] = 0;
    }
}

// Retrieves value of marbles in end zone.

int Positions::getEndZones(int loc)
{
    loc = endZones[loc];
    return loc;
}

// Increments marbles in end zone.

void Positions::incrementMarblesInEndZone(int loc)
{
    endZones[loc] = endZones[loc] + 1;
}

//Constructor

Positions::Positions()
{
   for (int i = 0; i < numSquares; i++)
   {
       squares[i] = 0;
   }

   for (int i = 0; i < numEndZones; i++)
   {
       endZones[i] = 0;
   }

}
