#include "mousehit.h"
#include "ui_mousehit.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QDebug>
MouseHit::MouseHit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MouseHit)
{
    ui->setupUi(this);

    this->ui->btnStart->setEnabled(true);
    this->ui->btnStop->setEnabled(false);
    this->ui->btnReset->setEnabled(false);

    ms=new mouseScene();

    this->ui->mouseHitView->setScene(ms);
    hm=HandlerMouse::getInstance();
    connect(hm,SIGNAL(scoreSignal()),this,SLOT(addScore())); //单例模式信号
    score=0;
}

MouseHit::~MouseHit()
{
    delete ui;
}

void MouseHit::closeEvent(QCloseEvent *event)
{

    int ret=QMessageBox::question(this,"是否要退出","真的要退出么?");
    if(ret==QMessageBox::No)
     {
        event->ignore();
    }
}

void MouseHit::resizeEvent(QResizeEvent *event)
{
    qDebug()<<this->ui->mouseHitView->width()<<" "<<this->ui->mouseHitView->height();
}

void MouseHit::addScore()
{
    score+=10;
    this->ui->lcdNumber->display(score);
}

void MouseHit::on_pushButton_clicked()
{

}
void MouseHit::on_btnStart_clicked()
{
    this->ms->timer->start(800);
    this->ui->btnStart->setEnabled(false);
    this->ui->btnStop->setEnabled(true);
    this->ui->btnReset->setEnabled(true);
}

void MouseHit::on_btnStop_clicked()
{
    if(this->ui->btnStop->text()=="暂停")
    {
        this->ms->timer->stop();
        this->ui->btnStop->setText("继续");
        this->ms->setMousePause();
    }
    else
    {
        this->ui->btnStop->setText("暂停");
        this->ms->timer->start(800);
        this->ms->setMouseActive();
    }

}

void MouseHit::on_btnReset_clicked()
{
    this->ui->btnStart->setEnabled(true);
    this->ui->btnStop->setEnabled(false);

    this->ms->timer->stop();
    score=0;
    this->ui->lcdNumber->display(score);
    this->ui->btnStop->setText("暂停");
    this->ms->setMousePause();
}
