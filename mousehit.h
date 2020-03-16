#ifndef MOUSEHIT_H
#define MOUSEHIT_H

#include "mousescene.h"

#include <QMainWindow>
#include "handlermouse.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MouseHit; }
QT_END_NAMESPACE

class MouseHit : public QMainWindow
{
    Q_OBJECT

public:
    MouseHit(QWidget *parent = nullptr);
    ~MouseHit();

private:
    Ui::MouseHit *ui;
    mouseScene *ms;
    void closeEvent(QCloseEvent *event);

    void resizeEvent(QResizeEvent *event);


    HandlerMouse *hm;
    int score;
private slots:
    void addScore();

    void on_pushButton_clicked();
    void on_btnStart_clicked();
    void on_btnStop_clicked();
    void on_btnReset_clicked();
};
#endif // MOUSEHIT_H
