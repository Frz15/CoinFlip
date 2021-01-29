#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mypushbutton.h"
#include "checkpointchoice.h"
#include <QAction>
#include <QPainter>
#include <QString>
#include <QTimer>
#include <QSound>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionquit, &QAction::triggered,[=](){
        this->close();
    });
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setFixedSize(320,588);
    this->setWindowTitle(QString("CoinFlip"));

    checkpointChoice = new CheckpointChoice();
    connect(checkpointChoice, &CheckpointChoice::chooseSceneBack, this, [=](){
        QTimer::singleShot(200,this, [=](){
            this->show();
        });
    });
    MypushButton* StartBtn = new MypushButton(QString(":/res/MenuSceneStartButton.png"));
    StartBtn->setParent(this);
    StartBtn->move(this->width()*0.5-StartBtn->width()*0.5, this->height()*0.7);
    connect(StartBtn, &QPushButton::pressed,[=](){
        StartBtn->down();
    });
    connect(StartBtn, &QPushButton::released,[=](){
        QSound* startSound = new QSound(":/res/TapButtonSound.wav");
        startSound->play();
        StartBtn->up();
        QTimer::singleShot(200,this,[=](){
            this->hide();
            checkpointChoice->show();
        });
    });
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap BG(":/res/PlayLevelSceneBg.png");
    BG = BG.scaled(this->width(), this->height());
    painter.drawPixmap(0,0,BG);

    QPixmap Title(":/res/Title.png");
    Title = Title.scaled(Title.width() * 0.5, Title.height() * 0.5);
    painter.drawPixmap(10,30,Title);
}

MainWindow::~MainWindow()
{
    delete ui;
}

