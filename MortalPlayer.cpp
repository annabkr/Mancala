#include <iostream>
#include <limits>
#include "MortalPlayer.h"

using namespace std;


//Prompts Player 1 [Mortal] to select a position. Ensure selection is valid.

void MortalPlayer::setUserSelection(Positions& myPositions)
{
    int a = 1;
    userSelection = 0;

    do
    {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');

         cout << endl;
         cout << "Please enter a position: " << endl;
         cin >> userSelection;
    }

    while (cin.bad() || (userSelection <= 0) || (userSelection > 10) || (userSelection == 8) || (myPositions.getMarbles(userSelection-1)) == 0);


}

//Retrieves user selection.

int MortalPlayer::getUserSelection(int& select)
{
    select = userSelection;
    return select;
}

//Sets direction, if user selects the center position.

void MortalPlayer::setDirection()
{
    do {
        cout << "Would you like to move right or left? (L/R)" << endl << " ";
        cin >> direction;
        }

        while (cin.bad() || (direction != 'R' && direction != 'L'));
}

//Retrieves direction.

char MortalPlayer::getDirection(char& direct)
{
    direct = direction;
    return direct;
}

//
// If user decides to play on 'difficult' mode, they will be prompted for a number between 1-100 to be compared with
// a randomly generated number, as well as Gerty [Player 2]'s choice.
//
//

void MortalPlayer::setLetMeGoFirst()
{

    do {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << " OK. Let's determine which player will go first. " << endl;
        cout << endl;
        cout << " I have randomly generated a number between 1 and 100. " << endl;
        cout << endl;
        cout << " Each player will guess a number. The player who is closest to my number wins. " << endl;
        cout << endl;
        cout << " Enter a number between 1 and 100." << endl;
        cout << endl;
        cin >> letMeGoFirst;
    }
    while (cin.bad() || letMeGoFirst <=0 || letMeGoFirst > 100);
}

// Retrieves selection for the 'difficult' mode mini-game.

int MortalPlayer::getLetMeGoFirst(int& select)
{
    select = letMeGoFirst;
    return select;
}

//Constructor

MortalPlayer::MortalPlayer()
{
    userSelection = 0;

    direction = 'a';

    letMeGoFirst = 0;
}

//Destructor

MortalPlayer::~MortalPlayer()
{

}
