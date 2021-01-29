#include "playscene.h"
#include "ui_playscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QLabel>
#include "mycoin.h"
#include "dataconfig.h"
#include <QVector>
#include <QDebug>
#include <QPropertyAnimation>

PlayScene::PlayScene(int levelIndex):
    ui(new Ui::PlayScene)
{
    this->m_levelIndex = levelIndex;
    ui->setupUi(this);
    this->setFixedSize(320,588);
    //返回按钮
    MypushButton* backBtn = new MypushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(), this->height()-backBtn->height());

    //点击返回
    connect(backBtn, &QPushButton::clicked,[=](){
        this->hide();
        emit this->playSceneBack();
    });

    QLabel * label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString str = QString("Leavel: %1").arg(this->m_levelIndex);
    label->setText(str);
    label->setGeometry(QRect(30, this->height() - 50,120, 50));

    dataConfig* data = new dataConfig();

    QMap<int, QVector< QVector<int>>> levelData = data->mData;
    QVector< QVector<int>> allCoinData;
    allCoinData = levelData.value(levelIndex);

    QPushButton* winBtn = new QPushButton(this);
    QPixmap winPix(QString(":/res/LevelCompletedDialogBg.png"));
    QIcon winIcon(winPix);
    winBtn->setFixedSize(winPix.width(), winPix.height());
    winBtn->setStyleSheet("QPushButton{border:0px;}");
    winBtn->setIcon(winIcon);
    winBtn->setIconSize(QSize(winPix.width(), winPix.height()));
    winBtn->move((this->width()-winBtn->width())*0.5, -winBtn->height());
    QPropertyAnimation* winBtnProAni = new QPropertyAnimation(winBtn, "geometry");
    winBtnProAni->setDuration(1000);
    winBtnProAni->setStartValue(QRect(winBtn->x(), winBtn->y(), winBtn->width(), winBtn->height()));
    winBtnProAni->setEndValue(QRect(winBtn->x(), 0.7*winBtn->height(), winBtn->width(), winBtn->height()));
    winBtnProAni->setEasingCurve(QEasingCurve::OutBounce);

    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
           //绘制背景图片
            QLabel* label = new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->setParent(this);
            label->move(57 + i*50, 200+j*50);
            int coinIndex = allCoinData[i][j];
            coins[i][j] = new MyCoin(i,j,coinIndex);
            coins[i][j]->setParent(this);
            coins[i][j]->move(59 + i*50, 202+j*50);
            connect(coins[i][j], &QPushButton::clicked, this, [=](){
                coins[i][j]->changeIcon();
                QTimer::singleShot(120,[=](){
                    if(i>0){
                        coins[i-1][j]->changeIcon();
                    }
                    if(i < 3){
                        coins[i+1][j]->changeIcon();
                    }
                    if(j > 0){
                        coins[i][j-1]->changeIcon();
                    }
                    if(j < 3){
                        coins[i][j+1]->changeIcon();
                    }
                    this->isWin = true;
                    for(int i=0; i<4; i++){
                        for(int j=0; j<4; j++){
                            if(coins[i][j]->m_coinIndex == 0){
                                this->isWin = false;
                            }
                        }
                    }
                    if(this->isWin){
                        emit win();
                        for(int i=0; i<4; i++){
                            for(int j=0; j<4; j++){
                                    coins[i][j]->win = true;
                            }
                        }
                    }
                });
            });
        }
    }

    connect(this, &PlayScene::win, this, [=](){
        qDebug() << "胜利！";
        winBtnProAni->start();
    });
}

void PlayScene::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap BG(":/res/PlayLevelSceneBg.png");
    BG = BG.scaled(this->width(), this->height());
    painter.drawPixmap(0,0,BG);

    QPixmap Title(":/res/Title.png");
    painter.drawPixmap((this->width()-Title.width())*0.5, 30, Title);

    QPixmap CoinBG(":/res/BoardNode.png");

};

PlayScene::~PlayScene()
{
    delete ui;
}
