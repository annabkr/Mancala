#include <iostream>
#include "conio.h"
#include "Options.h"

using namespace std;

void Options::showInstructions()
{
    char a;

    do {
    cout << endl;
    cout << " Welcome, Player 1." << endl;
    cout << endl;
    cout << " Would you like to read instructions for how to play the game? (Y/N) ";
    cout << endl;
    cout << " ";
    cin  >> a;
    }
    while (cin.bad() || (a != 'Y' && a != 'N'));

    if (a == 'Y')
    {
        cout << endl;
        cout << " -------------------------------------------------------------------------------------------- " << endl;
        cout << "                                           INTRODUCTION                                       " << endl;
        cout << " -------------------------------------------------------------------------------------------- " << endl;
        cout << " There are two players. You (Player 1) and Gerty (Player 2). "<< endl;
        cout << endl;
        cout << " Gerty is a computer player, but don't be alarmed. He is smart, but predictable." << endl;
        cout << endl;
        cout << " Each square on the board represents a selectable position. Each rectangle represents an end zone. " << endl;
        cout << endl;
        cout << " The position numbers (1 - 10) can be seen in the Position Key to the right of the board. " << endl;
        cout << endl;
        cout << " Your (Player 1)'s end zone is on the right. Gerty (Player 2)'s end zone is on the left. "<< endl;
        cout << endl;
        cout << " The number inside of the square or rectangle represents the number of marbles there. " << endl;
        cout << " -----------------------------------------------------------  " << endl;

        cout << "Press any key to continue." << endl;

        getch();

        cout << " -------------------------------------------------------------------------------------------- " << endl;
        cout << "                                          HOW TO PLAY                                         " << endl;
        cout << " -------------------------------------------------------------------------------------------- " << endl;
        cout << " The goal is to get as many marbles as possible into your end zone. " << endl;
        cout << endl;
        cout << " On your turn, select a position with marbles in it. " << endl;
        cout << endl;
        cout << " All of the marbles will be taken out of that position. " << endl;
        cout << endl;
        cout << " They will move along the numerical path outlined in the Position Key. " << endl;
        cout << endl;
        cout << " 1 Marble will be dropped in each position passed until all the marbles have been dropped. " << endl;
        cout << endl;
        cout << " If a player passes their opponent's end zone, it is skipped and no marble is dropped. " << endl;
        cout << endl;
        cout << " If a player passes over their OWN end zone, a marble is dropped. " << endl;
        cout << endl;
        cout << " If a player finishes their turn by dropping a marble in their end zone, they get another turn. " << endl;
        cout << endl;
        cout << " The game ends when a player has 5 marbles in their end zone. " << endl;
        cout << endl;
        cout << " At that point, the marbles remaining in the 4 right-hand holes will go into Player 1's end zone on the right " << endl;
        cout << endl;
        cout << " The marbles remaining in the 4 left-hand holes will go into Player 2's end zone on the left.  "<< endl;
        cout << endl;
        cout << " The Player whose end zone has the most marbles at the end, wins." << endl;
        cout << endl;

        cout << " Ready, Player One?! Press any key to continue. " << endl;
        getch();


    }
}
//Determines the distance between two integers.

int Options::determineDistance(int randomNumber, int someonesTurn, int& distance)
{
    bool roundOver = false;

    int copycatRando = randomNumber;
    int copycatTurn = someonesTurn;

    do
    {
        if (copycatRando == copycatTurn)
            {
                 roundOver = true;
            }
        else if (copycatRando > copycatTurn)
        {
            distance++;
            copycatRando--;
        }
        else if (copycatRando < copycatTurn)
        {
            distance++;
            copycatRando++;
        }
    }
    while (roundOver == false);

    return distance;

}

//This function determines which player goes first.
//The program generates a random number between 1 - 100.
//The computer player and mortal player "guess" a number within the same range.
//The player whose guess is closest to the original number, wins and goes first.

void Options::whoGoesFirst(MortalPlayer& myMortal, ComputerPlayer& myGerty, int& thisPlayerGoesFirst)
{

    int rando = rand()% 100 + 1; //Random number between 1 and 100.

    int mortalDistance = 0; // These integers will hold the distance between the player's guess
    int robotDistance = 0; // and the randomly generated number above.

    int mortalChoice = 0; //Initializes integer to receive Mortal's choice.

    int robotChoice = 0; //Initializes integer to receive Gerty's choice.

    myMortal.setLetMeGoFirst(); //Mortal player chooses a random number between 1 and 100.

    myGerty.setLetMeGoFirst(); //Computer player chooses a random number between 1 and 100.

    myMortal.getLetMeGoFirst(mortalChoice);
    myGerty.getLetMeGoFirst(robotChoice);

   while (mortalChoice == robotChoice)
    {
        cout << "You have guessed the same number as Gerty. Both players must try again." << endl;

        myMortal.setLetMeGoFirst();
        myGerty.setLetMeGoFirst();

        myMortal.getLetMeGoFirst(mortalChoice);
        myGerty.getLetMeGoFirst(robotChoice);
    }

    determineDistance(rando, mortalChoice, mortalDistance); // Distance between rando and mortalChoice is determined.

    determineDistance(rando, robotChoice, robotDistance); // Distance between rando and robotChoice is determined.

    if (mortalDistance < robotDistance)
    {
        cout << "Congratulations! Mortal wins!";
        cout << endl;
        cout << "Your guess was " << mortalDistance << " numbers away from the number. ";
        cout << endl;
        cout << "Gerty's guess was " << robotDistance << " numbers away from the number. ";
        cout << endl;

        thisPlayerGoesFirst = mortalWins;

        cout << "Press any key to continue. " << endl << " ";
        getch();

    }

    else if (mortalDistance > robotDistance)
    {
        cout << endl;
        cout << "Sorry. Gerty wins.";
        cout << endl;
        cout << "Your guess was " << mortalDistance << " numbers away from the number. ";
        cout << endl;
        cout << "Gerty's guess was " << robotDistance << " numbers away from the number. ";
        cout << endl;
        cout << endl;

        thisPlayerGoesFirst = gertyWins;


        cout << "Press any key to continue. " << endl << " ";
        getch();
    }
}

void Options::setDifficultMode ()
{
    char a;

    do {

        cout << endl;
        cout << " By default, the game is on 'EASY' mode and Player 1 has the advantage of going first. " << endl;
        cout << endl;
        cout << " Would you like to switch to 'DIFFICULT' mode and determine who will go first by playing my number-guessing game?  (Y/N)" << endl;
        cin >> a;

        }
        while (cin.bad() || (a != 'Y' && a != 'N'));

    if (a == 'Y')
    {
        difficultMode = true;
    }

    if (a == 'N')
    {
        difficultMode = false;
    }

}

bool Options::getDifficultMode(bool& diff)
{
    diff = difficultMode;
    return diff;
}

int Options::getMortalWins(int& winner)
{
    winner = mortalWins;
    return winner;
}


int Options::getGertyWins(int& winner)
{
    winner = gertyWins;
    return winner;
}

Options::Options()
{
    difficultMode = false;
}
