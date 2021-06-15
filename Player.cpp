#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "Bullet_h1.h"
#include "Bullet_h2.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bluster.mp3"));

}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+35,y());
        scene()->addItem(bullet);

        if(bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);}
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();}
    }
    else if (event->key() == Qt::Key_Shift){
        Bullet_h1 * bullet_h1 = new Bullet_h1();
        bullet_h1->setPos(x()+10,y());
        scene()->addItem(bullet_h1);

        Bullet_h2 * bullet_h2 = new Bullet_h2();
        bullet_h2->setPos(x()+70,y());
        scene()->addItem(bullet_h2);

        if(bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);}
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();}
    }
}

void Player::spawn(){
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
