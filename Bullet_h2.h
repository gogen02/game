#ifndef BULLET_H2_H
#define BULLET_H2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet_h2: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet_h2(QGraphicsItem * parent=0);
public slots:
    void move_h2();
//    void move_t();
};

#endif // BULLET_H
