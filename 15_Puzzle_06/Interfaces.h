#ifndef INTERFACES_H_
#define INTERFACES_H_

class IBoard
{
public :
    IBoard () {};
    virtual ~ IBoard () {};

    // Performs Steps random movements of the board to shuffle it.
    virtual void ShuffleBoard ( unsigned int Steps ) = 0 ;
    // Returns the block number at the given position . 0 is the
    // empty field . 1 to 15 represents corresponding titles .
    virtual unsigned int GetBlock ( unsigned int PosX ,	unsigned int PosY ) const = 0;
    // Moves the block at the given position , if possible .
    virtual bool MoveBlock ( unsigned int PosX , unsigned int PosY ) = 0 ;
};

class ISolver
{
public :
    ISolver () {} ;
    virtual ~ ISolver () {} ;
    // Solves the given board by moving its titles into the
    // original positions .
    virtual void Solve ( IBoard * pBoard ) = 0 ;
};

#endif /*INTERFACES_H_*/
