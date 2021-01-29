#include "mycoin.h"
#include <QPixmap>
#include <QIcon>
#include <QSize>
#include <QTimer>

MyCoin::MyCoin(int posX, int posY, int coinIndex)
{
    this->m_coinIndex = coinIndex;
    this->m_posX = posX;
    this->m_posY = posY;

    if (coinIndex == 0){
        QPixmap* coinPix = new QPixmap(QString(":/res/Coin0008.png"));
        this->setFixedSize(coinPix->width(), coinPix->height());
        this->setStyleSheet("QPushButton{border: 0px;}");
        this->setIcon(QIcon(*coinPix));
        this->setIconSize(QSize(coinPix->width(), coinPix->height()));
    }

    if (coinIndex == 1){
        QPixmap* coinPix = new QPixmap(QString(":/res/Coin0001.png"));
        this->setFixedSize(coinPix->width(), coinPix->height());
        this->setStyleSheet("QPushButton{border: 0px;}");
        this->setIcon(QIcon(*coinPix));
        this->setIconSize(QSize(coinPix->width(), coinPix->height()));
    }

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer1, &QTimer::timeout, this, [=](){
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        QPixmap pix = QPixmap(str);
        this->setIcon(QIcon(pix));
        if(this->min > this->max){
            this->min = 1;
            timer1->stop();
        }
    });
    connect(timer2, &QTimer::timeout, this, [=](){
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        QPixmap pix = QPixmap(str);
        this->setIcon(QIcon(pix));
        if(this->max < this->min){
            this->max = 8;
            timer2->stop();
        }
    });
}

void MyCoin::changeIcon(){

    if(this->m_coinIndex == 1)
    {
        timer1->start(30);
    }
    else if (this->m_coinIndex == 0)
    {
        timer2->start(30);
    }
    this->m_coinIndex = 1 - this->m_coinIndex;
}
