#include "Bullet_h1.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include <QtMath>
#include <QLabel>
#include <QMovie>

extern Game * game;

Bullet_h1::Bullet_h1(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap (":/pictures/bullet.png").scaled(30,30,Qt::KeepAspectRatio));

    QTimer * timer_h1 = new QTimer(this);
    connect(timer_h1,SIGNAL(timeout()),this,SLOT(move_h1()));
    timer_h1->start(30);
}

double t = M_PI;
void Bullet_h1::move_h1(){

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            QLabel *label = new QLabel(game);
            QMovie *movie = new QMovie(":/pictures/blueexplosion.gif");
             label->setMovie(movie);
             label->setGeometry(x()-35,y(), 100, 100);
             label->show();
             movie->start();
             delete colliding_items[i];
             delete this;
             connect(movie,SIGNAL(finished()),label,SLOT(deleteLater()));
            t = M_PI;
            return;
        }
    }
    if(t > -M_PI/2){
        t -= (M_PI_4)/4;
        double X = 16*sin(t)*sin(t)*sin(t);
        double Y = -13*cos(t)+5*cos(2*t)+2*cos(3*t)+cos(4*t);
        setPos(x()-X,y()+Y);
    } else {
        setPos(x(), y()-10);}
    QLabel *slabel = new QLabel(game);
    QMovie *smovie = new QMovie(":/pictures/smoke.gif");
     slabel->setMovie(smovie);
     slabel->setGeometry(x()-5,y()+10, 40, 40);
     smovie->setScaledSize(QSize(40,40));
     slabel->show();
     smovie->start();
     connect(smovie,SIGNAL(finished()),slabel,SLOT(deleteLater()));
    if (pos().y() + QRect().height() < 0){
        scene()->removeItem(this);
        delete this;
        t = M_PI;
    }
}
