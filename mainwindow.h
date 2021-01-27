#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include "checkpointchoice.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~MainWindow();
    CheckpointChoice* checkpointChoice = new CheckpointChoice();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
