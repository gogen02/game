#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include "Health.h"
#include <QMediaPlayer>
#include <QGraphicsItem>
#include <QMovie>
#include <QLabel>

Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    QPixmap bkgnd(":/pictures/background.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       scene->setBackgroundBrush(bkgnd);
       QLabel *blabel = new QLabel();
       QMovie *bmovie = new QMovie(":/pictures/backgroundgif.gif");
        blabel->setGeometry(50,50, 400, 400);
        bmovie->setScaledSize(QSize(400,400));
        bmovie->setParent(blabel);
        blabel->setWindowFlag(Qt::FramelessWindowHint);
        blabel->setAttribute(Qt::WA_NoSystemBackground, true);
        blabel->setAttribute(Qt::WA_TranslucentBackground, true);
        blabel->setMovie(bmovie);
        bmovie->start();

        scene->addWidget(blabel);


    player = new Player();
    player->setPixmap(QPixmap(":/pictures/spaceship.png").scaled(100,102));
    player->setPos(400,500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    QMediaPlayer * musicplayer = new QMediaPlayer();
    musicplayer->setMedia(QUrl("qrc:/sounds/background.mp3"));
    musicplayer->play();
    show();
}
