#ifndef CHECKPOINTCHOICE_H
#define CHECKPOINTCHOICE_H

#include <QMainWindow>
#include <QPaintEvent>
#include "playscene.h"

namespace Ui {
class CheckpointChoice;
}

class CheckpointChoice : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckpointChoice(QWidget *parent = nullptr);
    ~CheckpointChoice();
    void paintEvent(QPaintEvent* );
    PlayScene* play = NULL;


signals:
    void chooseSceneBack();

private:
    Ui::CheckpointChoice *ui;
};

#endif // CHECKPOINTCHOICE_H
