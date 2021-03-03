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
    Tree *tree = new Tree("un arbre de la classe tree", 100, 200);
    scene->addItem(tree);

    Npc *npc = new Npc("maitre yoda", 100,100);
    scene->addItem(npc);

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
