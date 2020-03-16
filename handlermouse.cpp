#include "handlermouse.h"

HandlerMouse::HandlerMouse(QObject *parent) : QObject(parent)
{

}

HandlerMouse * HandlerMouse::handlerMouse=new HandlerMouse;
HandlerMouse *HandlerMouse::getInstance()
{
    return handlerMouse;
}

void HandlerMouse::addScore()
{
    emit scoreSignal();
}

