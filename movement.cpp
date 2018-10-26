#include <iostream>
#include "Movement.h"

using namespace std;


void Movement::setPosition()
{
    position = 0;
}

int Movement::getPosition(int pos)
{
    pos = position;
    return pos;
}

void Movement::setDirection()
{
    direction = 0;
}

char Movement::getDirection(char dir)
{
    dir = direction;
    return dir;

}

void Movement::takeTurn(Positions& myPositions, Board& myBoard, int position, char direction, int& thisPlayerGoes, bool& getsAnotherTurn, bool& gameOver)
{
    //Each time the function is called, numMarbles is reset to 0.
    int numMarbles = 0;

    //Each time the function is called, the identity of the player is reset until determined.
    bool mortalIsPlaying = false;
    bool gertyIsPlaying = false;

    //Each time the function is called, whether the player gets another turn is reset to false.
    getsAnotherTurn = false;

    if (thisPlayerGoes == 1) //If the value 1 is passed to the function, the mortal player, Player 1, is playing.
    {
        mortalIsPlaying = true;
    }

    else if (thisPlayerGoes == 2) //If the value 2 is passed to the function, the computer player, Player 2 (Gerty) is playing.
    {
        gertyIsPlaying = true;
    }

    switch (position){
            case 1:
            case 2:
            case 4:
            case 5:
                    {

                        position--; //Adjusts location to proper position in the array.

                        numMarbles = myPositions.getMarbles(position); // Number of marbles becomes the integer in this square.

                        myPositions.emptyMarbles(position, numMarbles); //Takes all the marbles out.

                        position ++; //Moves to the next position.

                        int remainingMarbles = numMarbles; //Makes a copy of numMarbles to decrease within the loop

                        bool hasPassedEZ1Before = false;

                        for (int i = 0; i < numMarbles; i++){ //Use all the marbles in a turn.

                                if (remainingMarbles > 0){

                                    if (position == 5 && hasPassedEZ1Before == false && mortalIsPlaying == true) //If Mortal is playing, increments marbles in Player 1's End Zone.
                                            {
                                                myPositions.incrementMarblesInEndZone(0);
                                                remainingMarbles--;

                                                if (remainingMarbles == 0 && mortalIsPlaying == true)
                                                {
                                                    getsAnotherTurn = true; //Will give Player 1 another turn if they finish in their end zone.
                                                }

                                                hasPassedEZ1Before = true;

                                            }


                                    if (position > 5 && hasPassedEZ1Before == true) //Reset hasPassedEZ2Before, so it can pass over Endzone again if it has enough marbles to go all the way around.
                                        {
                                            hasPassedEZ1Before = false;
                                        }


                                    if (position == 7) //Increments marbles in the middle section if approached from the right to left path.
                                        {
                                            myPositions.incrementMarblesInSquare(2);
                                            position++;
                                            remainingMarbles--;
                                        }


                                    if (position == 10 && gertyIsPlaying == true) //If Gerty is playing and reaches his End Zone.
                                        {
                                            myPositions.incrementMarblesInEndZone(1); //Increment marbles in his End Zone.
                                            remainingMarbles--; //Decrement marbles.
                                            position = 0; //Reset location to 0 to start the circle over again.


                                            if (remainingMarbles == 0 && gertyIsPlaying == true)
                                                {
                                                    getsAnotherTurn = true; //Gives Gerty another turn if he finishes in his End Zone.
                                                }
                                        }


                                    if (position == 10 && mortalIsPlaying == true) //If Mortal is playing and reaches the end.
                                        {
                                            position = 0; //Skip End Zone. Reset location to 0 to start path again.
                                        }

                                    else{
                                            myPositions.incrementMarblesInSquare(position); //Increases the value stored in this bin by 1.
                                            position++; //Increase number to access next bin.
                                            remainingMarbles--; //Decrease remaining marbles.
                                            }
                                        }
                                    }
                                }
                                        break;

            case 6:
            case 7:
            case 9:
            case 10:
                    {
                        position--; //Adjusts location to proper position in the array.

                        numMarbles = myPositions.getMarbles(position); // Number of marbles becomes the integer in the square located here.

                        myPositions.emptyMarbles(position, numMarbles); //Takes all the marbles out.

                        position ++; //Moves to the next position.

                        int remainingMarbles = numMarbles; //Makes a copy of numMarbles to decrease within the loop

                        for (int i = 0; i < numMarbles; i++){

                                if (remainingMarbles > 0){

                                    if (position == 10 && gertyIsPlaying == true) //If Gerty is playing and reaches his End Zone.
                                        {
                                            myPositions.incrementMarblesInEndZone(1); //Increment marbles in his End Zone.
                                            remainingMarbles--; //Decrement marbles.
                                            position = 0; //Reset location to 0 to start the circle over again.

                                                if (remainingMarbles == 0 && gertyIsPlaying == true)
                                                {
                                                    getsAnotherTurn = true;
                                                }
                                        }

                                    if (position == 10 && mortalIsPlaying == true) //If Mortal is playing and reaches the end.
                                        {
                                            position = 0; //Skip End Zone. Reset location to 0 to start path again.

                                        }

                                    if (position == 7) //Increments the marbles in the middle position, if approached from right to left path.
                                        {
                                            myPositions.incrementMarblesInSquare(2);
                                            position++;
                                            remainingMarbles--;
                                        }

                                    else
                                        {
                                            myPositions.incrementMarblesInSquare(position); //Increases the value stored in this bin by 1.
                                            position++; //Increase number to access next bin.
                                            remainingMarbles--; //Decrease remaining marbles.
                                        }

                                    bool hasPassedEZ1Before = false;

                                    if (position == 5 && hasPassedEZ1Before == false && mortalIsPlaying == true) //If Mortal is playing, increments marbles in Player 1's End Zone.
                                            {
                                                myPositions.incrementMarblesInEndZone(0);
                                                remainingMarbles--;

                                                if (remainingMarbles == 0 && mortalIsPlaying == true)
                                                {
                                                    getsAnotherTurn = true; //Will give Player 1 another turn if they finish in their end zone.
                                                }

                                                hasPassedEZ1Before = true;

                                            }

                                    if (position > 5 && hasPassedEZ1Before == true) //Reset hasPassedEZ2Before, so it can pass over Endzone again if it has enough marbles to go all the way around.
                                        {
                                            hasPassedEZ1Before = false;
                                        }

                                    }
                                }
                            }

                            break;
            case 3:
                    if (direction == 'L')
                    {
                        position--; //Adjusts location to proper position in the array.

                        numMarbles = myPositions.getMarbles(position); // Number of marbles becomes the integer in the square located here.

                        myPositions.emptyMarbles(position, numMarbles); //Takes all the marbles out.

                        position = 8; //Moves to the next position to the left.

                        int remainingMarbles = numMarbles; //Makes a copy of numMarbles to decrease within the loop

                        for (int i = 0; i < numMarbles; i++){

                                if (remainingMarbles > 0){

                                        if (position == 10 && gertyIsPlaying == true) //If Gerty is playing and reaches his End Zone.
                                            {
                                            myPositions.incrementMarblesInEndZone(1); //Increment marbles in his End Zone.
                                            remainingMarbles--; //Decrement marbles.
                                            position = 0; //Reset position to 0 to start the circle over again.

                                                if (remainingMarbles == 0 && gertyIsPlaying == true)
                                                {
                                                    getsAnotherTurn = true;
                                                    break;
                                                }
                                            }

                                    if (position == 10 && mortalIsPlaying == true) //If Mortal is playing and reaches the end.
                                            {
                                            position = 0; //Skip End Zone. Reset position to 0 to start path again.
                                            }

                                    if (position == 7) //Increments the middle position if approached from right to left path.
                                            {
                                            myPositions.incrementMarblesInSquare(2);
                                            position++;
                                            remainingMarbles--;
                                            }

                                    else
                                            {
                                            myPositions.incrementMarblesInSquare(position); //Increases the value stored in this bin by 1.
                                            position++; //Increase number to access next bin.
                                            remainingMarbles--; //Decrease remaining marbles.
                                            }
                                        }
                                }
                        }

                    if (direction == 'R')
                    {

                        position--; //Adjusts location to proper position in the array.

                        numMarbles = myPositions.getMarbles(position); // Number of marbles becomes the integer in this square.

                        myPositions.emptyMarbles(position, numMarbles); //Takes all the marbles out.

                        position ++; //Moves to the next position.

                        int remainingMarbles = numMarbles; //Makes a copy of numMarbles to decrease within the loop

                        bool hasPassedEZ1Before = false;

                        for (int i = 0; i < numMarbles; i++){ //For all marbles.

                                if (remainingMarbles > 0){

                                        if (position == 5 && hasPassedEZ1Before == false && mortalIsPlaying == true) //If Mortal is playing, increments marbles in Player 1's End Zone.

                                            {
                                                myPositions.incrementMarblesInEndZone(0);
                                                remainingMarbles--;

                                                    if (remainingMarbles == 0 && mortalIsPlaying == true)
                                                    {
                                                        getsAnotherTurn = true;
                                                        break;
                                                    }

                                                hasPassedEZ1Before = true;

                                            }

                                        if (position == 7) //Increments marbles in middle position, if approached from right to left path.
                                        {
                                            myPositions.incrementMarblesInSquare(2);
                                            position++;
                                            remainingMarbles--;
                                        }

                                        if (position > 5 && hasPassedEZ1Before == true) //Reset hasPassedEZ2Before, so it can pass over Endzone again if it has enough marbles to go all the way around.
                                                {
                                                    hasPassedEZ1Before = false;
                                                }
                                        else{
                                                myPositions.incrementMarblesInSquare(position); //Increases the value stored in this bin by 1.
                                                position++; //Increase number to access next bin.
                                                remainingMarbles--; //Decrease remaining marbles.
                                                }
                                    }
                            }
                    }


                break;
            default:
                break;
        }

    //Determines if the game is over.
    if (myPositions.getEndZones(0) == 5 || myPositions.getEndZones(1) == 5)
    {
        gameOver = true;
    }

}

void Movement::endGame(Positions& myPositions, Board& myBoard)
{
    int marbles = 0;
    const int numPositions = 10;

    for (int i = 0; i < numPositions; i++)
    {
        if ( i >= 3 && i <= 6)
        {
            marbles = myPositions.getMarbles(i);
            myPositions.emptyMarbles(i, marbles);

            for (int j = 0; j < marbles; j++)
            {
                myPositions.incrementMarblesInEndZone(0);
            }
        }

        else if (i == 0 || i == 1 || i == 8 || i == 9)
        {
            marbles = myPositions.getMarbles(i);
            myPositions.emptyMarbles(i, marbles);

            for (int k = 0; k < marbles; k++)
                {
                    myPositions.incrementMarblesInEndZone(1);
                }
        }
    }
}

Movement::Movement()
{
     position = 0;
     direction = 'a';
}

Movement::~Movement()
{

}
