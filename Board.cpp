#include <iostream>
#include "Board.h"

using namespace std;

//Main board.

void Board::printBoard(Positions& myPositions, Movement& myMovement)
{
    cout << endl;
    cout << " 88b           d88                                                   88              " << endl;
    cout << " 888b         d888                                                   88              " << endl;
    cout << " 88`8b       d8'88                                                   88              " << endl;
    cout << " 88 `8b     d8' 88   adPPYYba,  8b,dPPYba,    ,adPPYba,   adPPYYba,  88   adPPYYba,  " << endl;
    cout << " 88  `8b   d8'  88         `Y8  88P'   `'8a  a8      Y8         'Y8  88          Y8  " << endl;
    cout << " 88   `8b d8'   88  ,adPPPPP88  88       88  8b          ,adPPPPP88  88  ,adPPPPP88  " << endl;
    cout << " 88    `888'    88  88,    ,88  88       88  '8a,   ,aa  88,    ,88  88  88,    ,88  " << endl;
    cout << " 88     `8'     88  `'8bbdP'Y8  88       88   `'Ybbd8'  `'8bbdP'Y8   88  ` '8bbdP'Y8 " << endl;
    cout << "_____________________________________________________________________________________" << endl;
    cout << "Program created by Anna Baker             Ascii logo adapted from http://patorjk.com/" << endl;
    cout << "   _____________________________________________________________________________             Position Key:    "      << endl;
    cout << "  |       _______   _______                           _______    _______       |         ____             ___  " << endl;
    cout << "  |      |       | |       |                         |       |  |       |      |        |_10_|___     ___|_5_| " << endl;
    cout << "  |      |       | |   "<<myPositions.getMarbles(9)<<"   |                         |   "<< myPositions.getMarbles(4) <<"   |  |       |      |             |_9_|___|_4_|     " << endl;
    cout << "  |      |       | |_______|_______           _______|_______|  |       |      |              ___|_3_|___      " << endl;
    cout << "  |      |       |         |       |         |       |          |       |      |          ___|_2_|   |_7_|___  " << endl;
    cout << "  |      |       |         |   "<< myPositions.getMarbles(8) <<"   |         |   "<< myPositions.getMarbles(3) <<"   |          |       |      |         |_1_|           |_6_| " << endl;
    cout << "  |      |       |         |_______| _______ |_______|          |       |      |                               " << endl;
    cout << "  |      |       |                  |       |                   |       |      |                               " << endl;
    cout << "  |      |   "<< myPositions.getEndZones(1) <<"   |                  |   " << myPositions.getMarbles(2) << "   |                   |   "<< myPositions.getEndZones(0) <<"   |      |                               " << endl;
    cout << "  |      |       |           _______|_______|_______            |       |      |                               " << endl;
    cout << "  |      |       |          |       |       |       |           |       |      |                               " << endl;
    cout << "  |      |       |          |   "<< myPositions.getMarbles(1) <<"   |       |  "<< myPositions.getMarbles(6) <<"    |           |       |      |                               " << endl;
    cout << "  |      |       |   _______|_______|       |_______|_______    |       |      |                               " << endl;
    cout << "  |      |       |  |       |                       |       |   |       |      |                               " << endl;
    cout << "  | //P  |       |  |   "<< myPositions.getMarbles(0) <<"   |                       |   "<< myPositions.getMarbles(5) << "   |   |       |  //P |                               " << endl;
    cout << "  | //2  |_______|  |_______|                       |_______|   |_______|  //1 |                               " << endl;
    cout << "  |____________________________________________________________________________|                               " << endl;


}

//Modified board to account for visual shift if Endzones contain double-digit marbles.

void Board::printEndGameBoard(Positions& myPositions, Movement& myMovement)
{
    cout << "88b           d88                                                   88              " << endl;
    cout << "888b         d888                                                   88              " << endl;
    cout << "88`8b       d8'88                                                   88              " << endl;
    cout << "88 `8b     d8' 88   adPPYYba,  8b,dPPYba,    ,adPPYba,   adPPYYba,  88   adPPYYba,  " << endl;
    cout << "88  `8b   d8'  88         `Y8  88P'   `'8a  a8      Y8         'Y8  88          Y8  " << endl;
    cout << "88   `8b d8'   88  ,adPPPPP88  88       88  8b          ,adPPPPP88  88  ,adPPPPP88  " << endl;
    cout << "88    `888'    88  88,    ,88  88       88  '8a,   ,aa  88,    ,88  88  88,    ,88  " << endl;
    cout << "88     `8'     88  `'8bbdP'Y8  88       88   `'Ybbd8'  `'8bbdP'Y8   88  ` '8bbdP'Y8 " << endl;
    cout << "_____________________________________________________________________________________" << endl;
    cout << "Program created by Anna Baker             Ascii logo adapted from http://patorjk.com/" << endl;
    cout << "   _____________________________________________________________________________             Positions:    "      << endl;
    cout << "  |       _______   _______                           _______    _______       |         ____             ___  " << endl;
    cout << "  |      |       | |       |                         |       |  |       |      |        |_10_|___     ___|_5_| " << endl;
    cout << "  |      |       | |   "<<myPositions.getMarbles(9)<<"   |                         |   "<< myPositions.getMarbles(4) <<"   |  |       |      |             |_9_|___|_4_|     " << endl;
    cout << "  |      |       | |_______|_______           _______|_______|  |       |      |              ___|_3_|___      " << endl;
    cout << "  |      |       |         |       |         |       |          |       |      |          ___|_2_|   |_7_|___  " << endl;
    cout << "  |      |       |         |   "<< myPositions.getMarbles(8) <<"   |         |   "<< myPositions.getMarbles(3) <<"   |          |       |      |         |_1_|           |_6_| " << endl;
    cout << "  |      |       |         |_______| _______ |_______|          |       |      |                               " << endl;
    cout << "  |      |       |                  |       |                   |       |      |                               " << endl;
    cout << "  |      |   " << myPositions.getEndZones(1);

        if ((myPositions.getEndZones(1)) < 10)   //Account for shifting of the board in case over 10 marbles
        {
            cout << " ";
        }

    cout <<"  |                  |   " << myPositions.getMarbles(2) << "   |                   |   "<< myPositions.getEndZones(0);

        if ((myPositions.getEndZones(0)) < 10)   //Account for shifting of the board in case over 10 marbles
        {
            cout << " ";
        }

    cout << "  |      |                               " << endl;
    cout << "  |      |       |           _______|_______|_______            |       |      |                               " << endl;
    cout << "  |      |       |          |       |       |       |           |       |      |                               " << endl;
    cout << "  |      |       |          |   "<< myPositions.getMarbles(1) <<"   |       |  "<< myPositions.getMarbles(6) <<"    |           |       |      |                               " << endl;
    cout << "  |      |       |   _______|_______|       |_______|_______    |       |      |                               " << endl;
    cout << "  |      |       |  |       |                       |       |   |       |      |                               " << endl;
    cout << "  | //P  |       |  |   "<< myPositions.getMarbles(0) <<"   |                       |   "<< myPositions.getMarbles(5) << "   |   |       |  //P |                               " << endl;
    cout << "  | //2  |_______|  |_______|                       |_______|   |_______|  //1 |                               " << endl;
    cout << "  |____________________________________________________________________________|                               " << endl;


}
