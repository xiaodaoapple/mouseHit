#ifndef MOUSESCENE_H
#define MOUSESCENE_H
#include "mouseitem.h"

#include <QGraphicsScene>
#include <QTimer>

class mouseScene : public QGraphicsScene
{
    Q_OBJECT
public:
    mouseScene();
    QTimer *timer;
    QVector<MouseItem *> vMouseItem; //mouse number

    void setMousePause();
    void setMouseActive();
public slots:
    void randomMouse();
    void addScore();
};

#endif // MOUSESCENE_H
