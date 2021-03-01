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
    // window settup
    view->setWindowIcon(QIcon(":/sprites/icon.png"));
    view->setWindowTitle("Zeldo");
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(600, 600);

    // in-game window setup
    view->setBackgroundBrush(QBrush(QImage(":/sprites/bg.png")));
    view->setSceneRect(0, 0, 600, 600);
    scene->setStickyFocus(true);
    view->setScene(scene);
    view->show();

    // map setup
    Entity *entity1 = new Entity("un premier test", 100, 100, QPixmap(":/sprites/tree.png"));
    Entity *entity2 = new Entity("un premier test", 100, 200, QPixmap(":/sprites/tree.png"));
    scene->addItem(entity1);
    scene->addItem(entity2);

    // player setup
    Player *player = new Player();
    player->setPos(50, 50);
    scene->addItem(player);

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setYOffset(-5);

    //QGraphicsBlurEffect *blur = new QGraphicsBlurEffect();
    //blur->setBlurRadius(1.25);

    //QGraphicsOpacityEffect *opa = new QGraphicsOpacityEffect();
    //opa->setOpacity(0.2);

    player->setGraphicsEffect(shadow);


}
