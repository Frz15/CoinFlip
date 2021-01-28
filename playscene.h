#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

namespace Ui {
class PlayScene;
}

class PlayScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayScene(QWidget *parent = nullptr);
    ~PlayScene();

private:
    Ui::PlayScene *ui;
};

#endif // PLAYSCENE_H
