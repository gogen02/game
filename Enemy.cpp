#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    int random_number = rand() % 700;
    setPos(random_number,0);

    QPixmap cheliki(":/pictures/cheliki.png");
    cheliki = cheliki.scaled(100,100,Qt::KeepAspectRatio);
    setPixmap(cheliki);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    setPos(x(),y()+5);

    if (pos().y() > 600){
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
