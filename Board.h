#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "Positions.h"
#include "Movement.h"
class Movement;
class Positions;


//
// This class controls the display of the board.
//
//

class Board
{
public:
    Board();
    ~Board();

    void printBoard(Positions& myPositions, Movement& myMovement);
    void printEndGameBoard(Positions& myPositions, Movement& myMovement);

private:

};


#endif // BOARD_H_INCLUDED
