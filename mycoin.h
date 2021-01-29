#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>
#include <QMouseEvent>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(int posX, int posY, int coinIndex);
    void changeIcon();
    int m_posX;
    int m_posY;
    QTimer* timer1;
    QTimer* timer2;
    int min=1;
    int max=8;
    int m_coinIndex;
    void mousePressEvent(QMouseEvent* e);
    bool win = false;

signals:

};

#endif // MYCOIN_H
