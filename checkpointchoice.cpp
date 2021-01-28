#include "checkpointchoice.h"
#include "ui_checkpointchoice.h"
#include <QPaintEvent>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include "mainwindow.h"
#include <QLabel>

CheckpointChoice::CheckpointChoice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckpointChoice)
{
    ui->setupUi(this);
    connect(ui->actionquit, &QAction::triggered,[=](){
        this->close();
    });
    this->setFixedSize(320,588);

    //返回按钮
    MypushButton* backBtn = new MypushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(), this->height()-backBtn->height());

    //点击返回
    connect(backBtn, &QPushButton::clicked,[=](){
        this->hide();
        emit this->chooseSceneBack();
    });

    for(int i=0; i<20; i++){
        MypushButton* menuBtn = new MypushButton(":/res/LevelIcon.png");
        menuBtn->move(25 + i%4 *70, 130 + i/4 * 70);
        menuBtn->setParent(this);
        connect(menuBtn, &MypushButton::clicked, [=](){
            QString str = QString("您选择的是第 %1 关 ").arg( i+1);
            qDebug() << str;
            PlayScene* play = new PlayScene(i+1);
            this->hide();
            play->show();
            connect(play, &PlayScene::playSceneBack, this, [=](){
                this->show();
            });
        });

        QLabel* label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25 + i%4 *70, 130 + i/4 * 70);
        label->setAlignment(Qt::AlignCenter);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void CheckpointChoice::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap BG(":/res/PlayLevelSceneBg.png");
    BG = BG.scaled(this->width(), this->height());
    painter.drawPixmap(0,0,BG);

    QPixmap Title(":/res/Title.png");
    painter.drawPixmap((this->width()-Title.width())*0.5, 30, Title);

};

CheckpointChoice::~CheckpointChoice()
{
    delete ui;
}
