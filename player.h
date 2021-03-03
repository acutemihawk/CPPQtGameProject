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

};

#endif // PLAYER_H
