#ifndef CHECKPOINTCHOICE_H
#define CHECKPOINTCHOICE_H

#include <QMainWindow>
#include <QPaintEvent>

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
signals:
    void chooseSceneBack();

private:
    Ui::CheckpointChoice *ui;
};

#endif // CHECKPOINTCHOICE_H
