#include "mypushbutton.h"
#include <QString>
#include <QIcon>
#include <QPixmap>
#include <QSize>
#include <QPropertyAnimation>

MypushButton::MypushButton(QString normalImg, QString clickImg)
{
    QPixmap pix(normalImg);

    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void MypushButton::down(){
    QPropertyAnimation* animationDown = new QPropertyAnimation(this, "geometry");
    animationDown->setDuration(200);
    animationDown->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animationDown->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animationDown->setEasingCurve(QEasingCurve::OutBounce);
    animationDown->start();

}

void MypushButton::up(){
    QPropertyAnimation* animationDown = new QPropertyAnimation(this, "geometry");
    animationDown->setDuration(200);
    animationDown->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animationDown->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    animationDown->setEasingCurve(QEasingCurve::OutBounce);
    animationDown->start();
}
