#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMap>
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
        QMap<int, bool> keys;
        QMap<int, bool> directionColliding;
};

#endif // PLAYER_H
