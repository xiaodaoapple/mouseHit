#include "mouseitem.h"

#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "handlermouse.h"

void MouseItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QCursor cu(QPixmap(":/hammer/images/hammerUp.png"));
    setCursor(cu);
}

void MouseItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    setCursor(QCursor(QPixmap(":/hammer/images/hammerDown.png")));

    HandlerMouse *hm=HandlerMouse::getInstance();
    if(isMouse && isStart)
   {
       //qDebug()<<"打中老鼠";
       hm->addScore();
       setMouseDown();
       isMouse=false;
   }
   else
    {
       //qDebug()<<"打的不是老鼠,或者已经打过老鼠";
    }

}

void MouseItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/hammer/images/hammerUp.png")));
}



MouseItem::MouseItem()
{
    itemOriginal=new QPixmap(":/mouse/images/mouseOriginal.png");
    mouseUp=new QPixmap(":/mouse/images/mouseUp.png");
    mouseDown=new QPixmap(":/mouse/images/mouseDown.png");
//    hammerUp=new QPixmap(":/hammer/images/hammerUp.png");
//    hammerDown=new QPixmap(":/hammer/images/hammerDown.png");

    setPixmap(*itemOriginal);
    isMouse=false;
    isStart=false;
}

void MouseItem::setStart(bool judge)
{
    isStart=judge;
}

void MouseItem::setMouseUp()
{

    setPixmap(*mouseUp);
}

void MouseItem::setMouseDown()
{

    setPixmap(*mouseDown);
}

void MouseItem::setOriginl()
{

    setPixmap(*itemOriginal);
}

void MouseItem::setMouseStatus(bool judge)
{
    isMouse=judge;
}

