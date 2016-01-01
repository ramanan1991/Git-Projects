#ifndef PUZZLEBOARD_H
#define PUZZLEBOARD_H
#include"Interfaces.h"

class PuzzleBoard : public IBoard{
public:
    PuzzleBoard();
    // Performs Steps random movements of the board to shuffle it.

    virtual void ShuffleBoard ( unsigned int Steps ) = 0 ;

    // Returns the block number at the given position . 0 is the
    // empty field . 1 to 15 represents corresponding titles .

    virtual unsigned int GetBlock ( unsigned int PosX ,	unsigned int PosY ) const = 0;

    // Moves the block at the given position , if possible .

    virtual bool MoveBlock ( unsigned int PosX , unsigned int PosY ) = 0 ;

};

#endif // PUZZLEBOARD_H
