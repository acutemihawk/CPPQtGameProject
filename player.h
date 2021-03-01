#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMap>
#include <QDebug>
#include "entity.h"

class Player: public QGraphicsPixmapItem
{
    public:
        Player();
        ~Player();
        void keyPressEvent(QKeyEvent * event);
        void keyReleaseEvent(QKeyEvent *event);
        void movePlayer();
        bool isColliding();
    private:
        int xCollision;
        int yCollision;
        int wCollision;
        int hCollision;
        QMap<int, bool> keys;
};

#endif // PLAYER_H
