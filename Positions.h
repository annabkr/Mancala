#ifndef POSITIONS_H_INCLUDED
#define POSITIONS_H_INCLUDED

//
// This class controls the positions on the board and their contents (marbles).
//

class Positions {

public:
    Positions();

    void setSquares();
    int getMarbles(int loc);
    void setEndZones();
    int getEndZones(int loc);


    void emptyMarbles(int loc, int marbles);
    void incrementMarblesInSquare(int loc);
    void incrementMarblesInEndZone(int loc);

private:
    const int numSquares = 10;
    const int numEndZones = 2;
    int squares[10];
    int endZones[2];
};



#endif // POSITIONS_H_INCLUDED
