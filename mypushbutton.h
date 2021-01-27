#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>

class MypushButton : public QPushButton
{
    Q_OBJECT
public:
    MypushButton(QString normalImg, QString clickImg="");
    void down();
    void up();
    QString m_clickImg;
    QString m_normalImg;
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent* );

};

#endif // MYPUSHBUTTON_H
