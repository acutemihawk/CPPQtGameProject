#ifndef GAME_H
#define GAME_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QImage>
#include "Player.h"
#include "map.h"

class Game
{
    private:
        Map *map;
        Player *player;
    public:
        Game();
        ~Game();
        void keyPressEvent(QKeyEvent * event);
        void keyReleaseEvent(QKeyEvent *event);
        void movePlayer();
        bool isColliding();
        void startGame();
        void level2();
};

#endif // GAME_H
