#ifndef CHECKPOINTCHOICE_H
#define CHECKPOINTCHOICE_H

#include <QMainWindow>

namespace Ui {
class CheckpointChoice;
}

class CheckpointChoice : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckpointChoice(QWidget *parent = nullptr);
    ~CheckpointChoice();

private:
    Ui::CheckpointChoice *ui;
};

#endif // CHECKPOINTCHOICE_H
