#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED
#include "MortalPlayer.h"
#include "ComputerPlayer.h"

//
// This class, "Options", contains additional options for the user that I feel enhance the game.
//
// The user has the option to play the game on "DIFFICULT" mode, where the player who gets to take the first turn
// is determined through a mini-game.
//
// The user also has the option to view instructions for the game and learn how to play.
//

class Options
{
public:
    Options();

    void showInstructions();            //When called, displays instructions for how to play the game.

    void setDifficultMode();            //User selects whether game will be played on difficult mode.
    bool getDifficultMode(bool& diff);

    int getMortalWins(int& winner);
    int getGertyWins(int& winner);

    void whoGoesFirst(MortalPlayer& myMortal, ComputerPlayer& myGerty, int& thisPlayerGoesFirst);
    int determineDistance(int randomNumber, int someonesTurn, int& distance);

private:

    bool difficultMode;

    const int mortalWins = 1; //Sets a constant value to be used when it is the Mortal [Player 1]'s turn.

    const int gertyWins = 2; //Sets a constant value to be used when it is Gerty [Player 2]'s turn.

};

#endif // OPTIONS_H_INCLUDED
