#include <iostream>
#include <stdlib.h>
#include "conio.h"
#include "time.h"
#include "Options.h"
#include "Board.h"
#include "Positions.h"
#include "Movement.h"
#include "MortalPlayer.h"
#include "ComputerPlayer.h"

using namespace std;

void playGame(Board& myBoard, Movement& myMovement, Positions& myPositions, MortalPlayer& myMortal, ComputerPlayer& myGerty, int& thisPlayerGoes);
void determineWinner(Positions myPositions);

int main()
{
    srand(time(NULL));

    Board myBoard;                                    //Creates board.
    Positions myPositions;                            //Creates positions.
    Movement myMovement;                              //Creates movement path.
    Options myOptions;                                //Creates options.
    MortalPlayer myMortal;                            //Creates Mortal [Player 1].
    ComputerPlayer myGerty;                           //Creates Gerty [Player 2].

    myPositions.setSquares();                         //Initializes squares.
    myPositions.setEndZones();                        //Initializes end zones.


    myBoard.printBoard(myPositions, myMovement);
    myOptions.showInstructions();                     // Gives user the option to read the instructions for the game.
    myBoard.printBoard(myPositions, myMovement);


    int thisPlayerGoesFirst = 1;                      // By default, the game is on "easy" mode and Player 1 will go first.

    bool switchMode = false;

    myOptions.setDifficultMode();                    //Gives user the option to play in difficult mode.
    myOptions.getDifficultMode(switchMode);          //If chosen, a mini-game will play to determine who goes first.

    if (switchMode == true)                         // Switches to difficult mode if selected by user.
    {                                               //Determines which player goes first.
        myBoard.printBoard(myPositions, myMovement);
        myOptions.whoGoesFirst(myMortal, myGerty, thisPlayerGoesFirst);
    }

    myBoard.printBoard(myPositions, myMovement);

    playGame(myBoard, myMovement, myPositions, myMortal, myGerty, thisPlayerGoesFirst); //Play game.
    determineWinner(myPositions); //Determine winner.

    return 0;
}


void playGame(Board& myBoard, Movement& myMovement, Positions& myPositions, MortalPlayer& myMortal, ComputerPlayer& myGerty, int& thisPlayerGoes)
{
    int position = 0;
    char direction = 'i';

    bool getsAnotherTurn = true;
    bool gameOver = false;

    do{
            if (thisPlayerGoes == 1 && getsAnotherTurn == true) //If Player 1's Turn...
            {

                    myMortal.setUserSelection(myPositions); //User will select a position.
                    myMortal.getUserSelection(position);

                    while (position == 0)
                    {
                        myMortal.setUserSelection(myPositions); //User will select a position.
                        myMortal.getUserSelection(position);
                    }

                    if (position == 3) //If they choose position 3, they will be prompted for direction L/R.
                        {
                            myMortal.setDirection();
                            myMortal.getDirection(direction);
                        }

                    myMovement.takeTurn(myPositions, myBoard, position, direction, thisPlayerGoes, getsAnotherTurn, gameOver);

                    myBoard.printBoard(myPositions, myMovement);

                    if (getsAnotherTurn == true && gameOver == false)
                    {
                        cout << endl;
                        cout << "GREAT SHOT! PLAYER 1 GETS ANOTHER TURN!" << endl;
                        cout << endl;
                    }

                        cout << endl;
                        cout << "You selected position " << position << "." << endl;
                        cout << endl;

                        cout << "Press any key to continue." << endl;
                        getch();
                        cout << endl;

                    if (getsAnotherTurn == false && gameOver == false)
                    {
                        cout << endl;
                        cout << "Now it's Gerty's turn." << endl;
                        cout << endl;

                        cout << "Press any key to continue." << endl;
                        getch();


                        thisPlayerGoes = 2;     //Next time it will be Player 2's Turn.
                        getsAnotherTurn = true;
                    }
            }

            if (thisPlayerGoes == 2 && getsAnotherTurn == true) //If Player 2's Turn...
            {

                    myGerty.setRobotSelection(myPositions);
                    myGerty.getRobotSelection(position);

                    if (position == 3)
                    {
                        myGerty.setDirection(myPositions);
                        myGerty.getDirection(direction);
                    }

                    myMovement.takeTurn(myPositions, myBoard, position, direction, thisPlayerGoes, getsAnotherTurn, gameOver);
                    myBoard.printBoard(myPositions, myMovement);

                    cout << endl;
                    cout << " Gerty selected position " << position << "." << endl;
                    cout << endl;

                    cout << " Press any key to continue." << endl;
                    getch();

                    if (getsAnotherTurn == true && gameOver == false)
                    {
                        cout << endl;
                        cout << " GREAT SHOT! PLAYER 2 GETS ANOTHER TURN!" << endl;
                        cout << " Press any key to continue." << endl;
                        getch();
                    }

                    if (getsAnotherTurn == false && gameOver == false)
                    {
                        cout << endl;
                        cout << " Now it's your turn." << endl;
                        cout << endl;
                        thisPlayerGoes = 1; //Next time it will be Player 1's Turn.
                        getsAnotherTurn = true;
                    }

            }

    } while (gameOver == false);

    if (gameOver == true)
    {
        thisPlayerGoes = 0;

        cout << endl;
        cout << " GAME OVER! "<< endl;
        cout << endl;

        cout << " Press any key to continue." << endl;
        getch();

        myMovement.endGame(myPositions, myBoard);
        myBoard.printEndGameBoard(myPositions, myMovement);

    }

}

void determineWinner(Positions myPositions)
{
    if ((myPositions.getEndZones(0)) > (myPositions.getEndZones(1)))
    {
        cout << endl;
        cout << " CONGRATULATIONS! MORTAL [PLAYER 1] WINS!" << endl;
        cout << endl;
    }
    else if ((myPositions.getEndZones(1)) > (myPositions.getEndZones(0)))
    {
        cout << endl;
        cout << " SORRY! GERTY [PLAYER 2] WINS!" << endl;
        cout << endl;
    }
}
