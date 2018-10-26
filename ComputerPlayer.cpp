#include <iostream>
#include "ComputerPlayer.h"

using namespace std;

//
// The computer player, Gerty [Player 2] determines optimal move based on his three-tiered logical criteria.
//

void ComputerPlayer::setRobotSelection(Positions& myPositions)
{
    int choice = 0;
    int largestSoFar= myPositions.getMarbles(0);
    int isLargest = 0;
    int closestToOpponent = 0;

    robotSelection = 0;

    bool found = false; // Resets value every time function is called and player makes a move

    if (robotSelection == 0)
    {

        canFinishInEndZone(myPositions, found, choice); //Check if there is a move available that would allow it to finish in its end zone.

        robotSelection = choice;

        if (found == false) //If not, selects the position with the most marbles on the right to left path.
            {
                {     findLargest(myPositions, found, largestSoFar, isLargest);

                        robotSelection = isLargest;
                }

             if (found == false) //If no marbles on the right to left path, selects the position closest to the opponent's end zone.
                {
                        binClosestToOpponent(myPositions, found, closestToOpponent);

                        robotSelection = closestToOpponent;
                }
            }
    }
}

//Retrieves Gerty [Player 2]'s selection.

int ComputerPlayer::getRobotSelection(int& selection)
{
    selection = robotSelection;
    return selection;
}

//
// Determines whether there is a position that will allow Gerty [Player 2] to finish his turn in his own end zone.
//

void ComputerPlayer::canFinishInEndZone(Positions& myPositions, bool& found, int& choice)
{
    //Resets the following values every time function runs.
    found = false;
    int location = 0;
    int requirement = 10;
    int numMarbles = 0;

     for (int i = 0; i < numPositions; i++){

                if (found == false)
                    {
                       if (location != 7 && location != 2)
                        {
                            // Uses modulo to determine for any number of marbles.
                            if ((myPositions.getMarbles(location) % 11) == requirement && (myPositions.getMarbles(location)) != 0)
                            {
                                choice = location + 1;
                                location++;
                                requirement--;
                                found = true;
                            }
                        }

                        if (location == 2 && (myPositions.getMarbles(location)) != 0)
                        {
                            if ((myPositions.getMarbles(2) % 11) == 8 || (myPositions.getMarbles(2) % 11) == 3)
                                {
                                    choice = location + 1;
                                    location++;
                                    requirement--;
                                    found = true;
                                }
                            else{
                                location++;
                                requirement--;
                                }
                        }
                else
                {
                    location++;
                    requirement--;
                }

        }
    }
}

//
// Determines the bin on the right to left path with the most marbles.
//

void ComputerPlayer::findLargest(Positions& myPositions, bool& found, int& largestSoFar, int& isLargest)
{
    found = false;
    largestSoFar = 0;
    isLargest = 0;

    for (int i = 5; i < numPositions; i++)
    {
       if (i != 7 && (myPositions.getMarbles(i)) > largestSoFar)
        {
            largestSoFar = myPositions.getMarbles(i);
            isLargest = i;
        }

    }

     if (myPositions.getMarbles(2) > largestSoFar)
        {
            largestSoFar = 2;
            isLargest = 2;
        }

        if (isLargest > 0)
        {
            found = true;
        }

        isLargest = isLargest +1;
    }

//
// Determines the bin closest to the opponent's end zone.
//

void ComputerPlayer::binClosestToOpponent(Positions& myPositions, bool& found, int& closestToOpponent)
{
    found = false;
    closestToOpponent = 0;

    int numRuns = 5;


    for (int i = 4; i < numRuns; i--)
    {
        if (myPositions.getMarbles(i) > 0)
        {
            cout << "It works!" << i << endl;
            closestToOpponent = i +1;
            cout << closestToOpponent << endl;
            found = true;
            numRuns = 0;
        }
    }

}

// If Gerty [Player 2] selects position 3, he will determine which direction he should go.

void ComputerPlayer::setDirection(Positions& myPositions)
{
                {
                    if ((myPositions.getMarbles(2)) % 11 == 8)
                    {
                        robotDirection = 'R';
                    }

                    if ((myPositions.getMarbles(2)) % 11 == 3)
                    {
                        robotDirection = 'L';
                    }
                    else
                    {
                        robotDirection = 'L';
                    }
                }

}

//Retrieves direction.

char ComputerPlayer::getDirection(char& direction)
{
    direction = robotDirection;

    return direction;
}

// Generates a random number between 1-100 to participate in the mini-game.

void ComputerPlayer::setLetMeGoFirst()
{
    letMeGoFirst = rand()% 100 + 1;
}

// Retrieves the number for the mini-game.

int ComputerPlayer::getLetMeGoFirst(int& selection)
{
    selection = letMeGoFirst;
    return selection;
}

//Constructor

ComputerPlayer::ComputerPlayer()
{
     robotSelection = 0;

     robotDirection = 0;

     letMeGoFirst = 0;

     numPositions = 10;

     halfTheBoard = 5;
}

//Destructor

ComputerPlayer::~ComputerPlayer()
{

}
