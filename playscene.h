#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

namespace Ui {
class PlayScene;
}

class PlayScene : public QMainWindow
{
    Q_OBJECT

public:
    PlayScene(int levelIndex);
    void paintEvent(QPaintEvent* );
    ~PlayScene();
    int m_levelIndex;
    MyCoin* coins[4][4];

signals:
    void playSceneBack();

private:
    Ui::PlayScene *ui;
};

#endif // PLAYSCENE_H
