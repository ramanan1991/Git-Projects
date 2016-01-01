#include "Puzzleblock.h"
#include<QKeyEvent>
#include<QGraphicsSceneMouseEvent>
#include<QDebug>



PuzzleBlock::PuzzleBlock()
{

}

void PuzzleBlock::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        setPos(x()-70,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+70,y());
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-70);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+70);
    }
}

void PuzzleBlock::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(event->button() == Qt::LeftButton)
    {
        qDebug() << "mouse clicked - My rect Coordinates with View"<<rect().x()<<rect().y();
        qDebug() << "mouse clicked - Current Coordinates"<<pos().x()<<pos().y();
        qDebug() << "mouse clicked - Previous Coordinates"<<rect().x()+pos().x();

        // check if the block can move right
        setPos(x()+75,y());
        qDebug() << "mouse clicked - Current Coordinates"<<rect().x()+pos().x();
        if(rect().x()+ pos().x()>230 || canMoveBlock() )

        {
            qDebug() << "in the If Block of Move right";
            setPos(x()-75,y());

            //check if the block can move Left
            setPos(x()-75,y());

            if(rect().x()+ pos().x()<5 || canMoveBlock())

            {
                qDebug() << "in the If Block of Move left";
                setPos(x()+75,y());

                //check if the block can move up
                setPos(x(),y()-75);

                if(rect().y()+ pos().y()<5 || canMoveBlock())

                {
                    qDebug() << "in the If Block of Move Up";
                    setPos(x(),y()+75);

                    //check if the block can move down
                    setPos(x(),y()+75);

                    if(rect().y()+ pos().y()>231 || canMoveBlock())

                    {
                        qDebug() << "in the If Block of Move down";
                           setPos(x(),y()-75);
                    }

                }
            }
        }
    }
}


bool PuzzleBlock::canMoveBlock(){
    QList<QGraphicsItem *> list = collidingItems() ;
    if(!list.isEmpty()){
        qDebug() << "list";
        foreach(QGraphicsItem * i , list)
        {

            PuzzleBlock * item= dynamic_cast<PuzzleBlock *>(i);
            if (item)
            {
                qDebug() << "Colliding";
                return true;

            }
            else
            {
                qDebug() << "not Colliding";
                return false;
            }
        }}else{
        qDebug() << "Collision list empty";
        return false;}}
