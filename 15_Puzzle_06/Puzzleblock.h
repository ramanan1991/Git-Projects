#ifndef PUZZLEBLOCK_H
#define PUZZLEBLOCK_H
#include<QGraphicsRectItem>

class PuzzleBlock : public QGraphicsRectItem{
public:
    PuzzleBlock();
    void keyPressEvent(QKeyEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    bool canMoveBlock();
};

#endif // PUZZLEBLOCK_H
