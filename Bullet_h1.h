#ifndef BULLET_H1_H
#define BULLET_H1_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet_h1: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet_h1(QGraphicsItem * parent=0);
public slots:
    void move_h1();
//    void move_t();
};

#endif // BULLET_H
