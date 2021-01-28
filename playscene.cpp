#include "playscene.h"
#include "ui_playscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QLabel>

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

    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
           //绘制背景图片
            QLabel* label = new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->setParent(this);
            label->move(57 + i*50,200+j*50);
        }
    }
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
