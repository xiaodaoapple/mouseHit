#ifndef MOUSEITEM_H
#define MOUSEITEM_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class MouseItem : public QGraphicsPixmapItem
{

private:

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    bool isStart;
      QPixmap *mouseUp;
      QPixmap *mouseDown;
      QPixmap *itemOriginal;
//      QPixmap *hammerUp;
//      QPixmap *hammerDown;
signals:
      void mouseHited();
public:
    MouseItem();
    void setStart(bool judge);

     bool isMouse;  //judge item is mouse;
public slots:
    void setMouseUp();
    void setMouseDown();
    void setOriginl();
    void setMouseStatus(bool judge);

};

#endif // MOUSEITEM_H
