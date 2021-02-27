#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsRectItem>

#include <QImage>
#include "Player.h"

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
