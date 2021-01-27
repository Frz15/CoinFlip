#include "checkpointchoice.h"
#include "ui_checkpointchoice.h"

CheckpointChoice::CheckpointChoice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckpointChoice)
{
    ui->setupUi(this);
    connect(ui->actionquit, &QAction::triggered,[=](){
        this->close();
    });
}

CheckpointChoice::~CheckpointChoice()
{
    delete ui;
}
