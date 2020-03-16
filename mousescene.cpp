#include "mousescene.h"
#include <QDebug>
#include <QRandomGenerator>
mouseScene::mouseScene()
{
   MouseItem temp;
   QRectF rect=temp.boundingRect();

   for(int i=0;i<16;++i)
   {
       MouseItem *mi=new MouseItem();
       vMouseItem.append(mi);
   }
   for(int i=0;i<4;++i)
      for(int j=0;j<4;++j)
      {
          vMouseItem[i*4+j]->setPos(j*rect.width(),i*rect.height());
      //    vMouseItem[i*4+j]->set
          addItem(vMouseItem[i*4+j]);
         // connect(vMouseItem[i*4+j],SIGNAL(mouseHited()),this,SLOT(addScore()));
      }

   timer =new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(randomMouse()));

   //  timer->start(800);
}

void mouseScene::setMousePause()
{
    QVector<MouseItem *>::iterator it=vMouseItem.begin();
    for(;it!=vMouseItem.end();++it)
    {
        (*it)->setStart(false);

    }
}

void mouseScene::setMouseActive()
{
    QVector<MouseItem *>::iterator it=vMouseItem.begin();
    for(;it!=vMouseItem.end();++it)
    {
        (*it)->setStart(true);
    }
}

void mouseScene::randomMouse()
{
    //qDebug()<<QRandomGenerator::global()->bounded(16);
    QVector<MouseItem *>::iterator it=vMouseItem.begin();
    for(;it!=vMouseItem.end();++it)
    {
        (*it)->setOriginl();
        (*it)->setMouseStatus(false);
    }

    int i=QRandomGenerator::global()->bounded(4); //产生老鼠的数目
    int k;
    for(int j=0;j<i;j++)
    {
        k=QRandomGenerator::global()->bounded(16);
        vMouseItem[k]->setMouseUp();
        vMouseItem[k]->setMouseStatus(true);
        vMouseItem[k]->setStart(true);
    }
}

void mouseScene::addScore()
{
    qDebug()<<"打了一次老鼠";
}
