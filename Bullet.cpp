#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include <QLabel>
#include <QMovie>
#include "Game.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/pictures/bullet.png").scaled(30,30,Qt::KeepAspectRatio));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            game->score->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
           QLabel *label = new QLabel(game);
           QMovie *movie = new QMovie(":/pictures/blueexplosion.gif");
            label->setMovie(movie);
            label->setGeometry(x()-35,y()-35, 100, 100);
            label->show();
            movie->start();
            delete colliding_items[i];
            delete this;
            connect(movie,SIGNAL(finished()),label,SLOT(deleteLater()));
            return;
        }
    }
    setPos(x(),y()-10);

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
    }
}
