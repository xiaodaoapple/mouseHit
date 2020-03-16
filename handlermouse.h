#ifndef HANDLERMOUSE_H
#define HANDLERMOUSE_H

#include <QObject>

class HandlerMouse : public QObject
{
    Q_OBJECT
private:
    explicit HandlerMouse(QObject *parent = nullptr);
public:
    static HandlerMouse *handlerMouse;
    static HandlerMouse * getInstance();
    void addScore();
signals:
    void scoreSignal();

};

#endif // HANDLERMOUSE_H
