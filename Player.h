#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMap>
#include "entity.h"
#include "gate.h"

class Player: public QGraphicsPixmapItem
{
    public:
        Player();
        ~Player();
        int getXCollision();
        void setXCollision(int value);
        int getYCollision();
        void setYCollision(int value);
        QMap<int, bool> getKeys();
        void setKeys(QMap<int, bool> &value);
        void setPixMap(QPixmap pixmap);
        void setPosition(int x,int y);
        qreal getX();
        qreal getY();
        QList<QGraphicsItem *> getColliding_items();
        void setColliding_items(QList<QGraphicsItem *> &value);

private:
        int xCollision;
        int yCollision;
        QMap<int, bool> keys;
        QList<QGraphicsItem *> colliding_items;
};

#endif // PLAYER_H
