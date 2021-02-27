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
    Entity *entity1 = new Entity("un premier test", 100, 100, QPixmap(":/sprites/tree.png"));
    entity1->boundingRect().setBottom(entity1->getY()+50);
    entity1->boundingRect().setTop(entity1->getY()-50);
    entity1->boundingRect().setRight(entity1->getX()+50);
    entity1->boundingRect().setLeft(entity1->getX()-50);
    scene->addItem(entity1);

    scene->addItem(player);


}
