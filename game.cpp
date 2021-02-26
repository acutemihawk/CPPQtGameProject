#include "game.h"

Game::Game()
{
    view = new QGraphicsView();
    scene = new QGraphicsScene();
}

Game::~Game()
{
    free(view);
    free(scene);
}

void Game::startGame()
{
    view->setBackgroundBrush(QBrush(QImage(":/sprites/bg.png")));
    view->setScene(scene);
    view->setWindowTitle("Zeldo");
    view->setFixedSize(1280, 720);
    view->show();

    Player *player = new Player();

    scene->addItem(player);


}
