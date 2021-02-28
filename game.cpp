#include "game.h"
#include "entity.h"

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
    view->setFixedSize(600, 600);
    view->show();

    Player *player = new Player();
    Entity *entity1 = new Entity("un premier test", 100, 100, QPixmap(":/sprites/tree2.png"));
    scene->addItem(entity1);
    Entity *entity2 = new Entity("un premier test", 100, 200, QPixmap(":/sprites/tree2.png"));
    scene->addItem(entity2);
    scene->addItem(player);


}
