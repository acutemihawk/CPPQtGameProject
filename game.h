#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QImage>
#include <QIcon>
#include <QGraphicsDropShadowEffect> // meilleure classe
#include <QGraphicsBlurEffect>
#include <QGraphicsOpacityEffect>

#include "entity.h"
#include "player.h"

class Game
{
    public:
        Game();
        ~Game();
        void startGame();
    protected:
    QGraphicsView *view;
    QGraphicsScene *scene;

};

#endif // GAME_H
