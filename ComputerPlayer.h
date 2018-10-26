#ifndef COMPUTERPLAYER_H_INCLUDED
#define COMPUTERPLAYER_H_INCLUDED
#include "Positions.h"
class Positions;


//
// This class controls the Computer Player, Gerty [Player 2] and his logic.
//
//

class ComputerPlayer
{
    public:
        ComputerPlayer();
        ~ComputerPlayer();

        void setRobotSelection(Positions& myPositions); //Gerty makes a selection, based on the required criteria.
        int getRobotSelection(int& selection);

        void setDirection(Positions& myPositions);  // Sets direction if Gerty picks the center square.
        char getDirection(char& direction);

        void setLetMeGoFirst(); //If Player 1 chooses to play on 'difficult' mode, Gerty chooses a random number between 1-100.
        int getLetMeGoFirst(int& selection);

        void canFinishInEndZone(Positions& myPositions, bool& found, int& choice); //Gerty determines if he can finish a turn in his own end zone.

        void findLargest(Positions& myPositions, bool& found, int& largestSoFar, int& isLargest); //If not, Gerty chooses the bin on the right to left path that has the most marbles.

        void binClosestToOpponent(Positions& myPositions, bool& found, int& closestToOpponent); //If no marbles on the right to left path, Gerty chooses the bin closest to Player 1's end zone.

    private:

        int robotSelection;

        char robotDirection;

        int letMeGoFirst;

        int numPositions;

        int halfTheBoard;

};

#endif // COMPUTERPLAYER_H_INCLUDED
