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
        int xCollision;
        int yCollision;
        QMap<int, bool> keys;
};

#endif // PLAYER_H
