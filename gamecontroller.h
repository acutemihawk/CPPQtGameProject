#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

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

class GameController: public QGraphicsPixmapItem
{
    public:
        GameController();
        ~GameController();
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

#endif // GAMECONTROLLER_H
