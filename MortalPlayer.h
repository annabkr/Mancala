#ifndef MORTALPLAYER_H_INCLUDED
#define MORTALPLAYER_H_INCLUDED
#include "Positions.h"
class Positions;


//
// This class is for the Mortal [Player 1] -- the human user.
//
//

class MortalPlayer
{
public:
    MortalPlayer();
    ~MortalPlayer();

    void setUserSelection(Positions& myPositions);
    int getUserSelection(int& select);

    void setDirection();
    char getDirection(char& direct);

    void setLetMeGoFirst();
    int getLetMeGoFirst(int& select);

private:

    int userSelection; // Integer to hold Mortal Player's user selection for each turn.

    char direction; // Integer to hold Mortal Player's choice in direction, if userSelection == 3.

    int letMeGoFirst; //Integer to determine who goes first.
};

#endif // MORTALPLAYER_H_INCLUDED
