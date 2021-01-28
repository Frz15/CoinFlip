#include "mycoin.h"
#include <QPixmap>
#include <QIcon>
#include <QSize>

MyCoin::MyCoin(int coinIndex)
{
    if (coinIndex == 0){
        QPixmap* coinPix = new QPixmap(QString(":/res/Coin0001.png"));
        this->setFixedSize(coinPix->width(), coinPix->height());
        this->setStyleSheet("QPushButton{border: 0px;}");
        this->setIcon(QIcon(*coinPix));
        this->setIconSize(QSize(coinPix->width(), coinPix->height()));
    }

    if (coinIndex == 1){
        QPixmap* coinPix = new QPixmap(QString(":/res/Coin0008.png"));
        this->setFixedSize(coinPix->width(), coinPix->height());
        this->setStyleSheet("QPushButton{border: 0px;}");
        this->setIcon(QIcon(*coinPix));
        this->setIconSize(QSize(coinPix->width(), coinPix->height()));
    }
}
