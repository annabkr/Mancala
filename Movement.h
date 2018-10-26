#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED
#include "Board.h"
#include "Positions.h"
class Board;
class Positions;

//
// This class controls the movement path of the marbles.
//
//

using namespace std;

class Movement
{
public:
    Movement();
    ~Movement();

    void setPosition();
    int getPosition(int pos);

    void setDirection();
    char getDirection(char dir);

    void takeTurn(Positions& myPositions, Board& myBoard, int position, char direction, int& whoIsPlaying, bool& getsAnotherTurn, bool& gameOver);
    void endGame(Positions& myPositions, Board& myBoard);

private:
    int position;
    char direction;
};

#endif // MOVEMENT_H_INCLUDED
