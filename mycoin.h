#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(int coinIndex);

signals:

};

#endif // MYCOIN_H
