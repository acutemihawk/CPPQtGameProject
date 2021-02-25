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
    view->setScene(scene);
    view->setWindowTitle("Zeldo");
    view->show();
    view->resize(500,500);

    Player *player = new Player();

    scene->addItem(player);


}
