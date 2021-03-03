#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsItem>

#include <QImage>
#include <QIcon>
#include <QGraphicsDropShadowEffect> // meilleure classe
#include <QGraphicsBlurEffect>
#include <QGraphicsOpacityEffect>
#include <QKeyEvent>

#include "entity.h"
#include "map.h"
#include "gate.h"

class Game: public QGraphicsPixmapItem
{
    public:
        Game();
        ~Game();
        void startGame();
        void keyPressEvent(QKeyEvent * event);
        void keyReleaseEvent(QKeyEvent *event);
        void movePlayer();
        bool isColliding();
        void clearLevel();
        void level1();
        void level2();

    private:
        Map *map;
        int xCollision;
        int yCollision;
        int wCollision;
        int hCollision;
        QMap<int, bool> keys;

};

#endif // GAME_H
