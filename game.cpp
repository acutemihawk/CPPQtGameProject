#include "game.h"
#include <QDebug>

Game::Game()
{
    map =new Map(QImage(":/sprites/bg.png"));
    setPixmap(QPixmap(":/sprites/devant1.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(0,0);
}

Game::~Game()
{

}

void Game::startGame()
{
    /*// window settup
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

    player->setGraphicsEffect(shadow);*/

    level1();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    keys[event->key()] = true;
    movePlayer();
}

void Game::keyReleaseEvent(QKeyEvent *event)
{
    keys[event->key()] = false;
}

void Game::movePlayer()
{
    if(keys[68] == true) // key D
    {
        if(isColliding() == false)
        {
            setPixmap(QPixmap(":/sprites/droite1.png"));
            setPos(x()+10, y());
        }
        else{
            // si on est à haut                                       bas                          droite
            if(y()+boundingRect().height() <= yCollision + 10 || y() >= hCollision - 10 || x() >= xCollision -10){
                setPixmap(QPixmap(":/sprites/droite1.png"));
                setPos(x()+10, y());
            }
            else
                setPixmap(QPixmap(":/sprites/droite1.png"));
        }
    }

    if(keys[81] == true) // key Q
    {
        if(isColliding() == false)
        {
            setPixmap(QPixmap(":/sprites/gauche1.png"));
            setPos(x()-10, y());
        }
        else{
            // si on est en haut                                    bas                          gauche
            if(y()+boundingRect().height() <= yCollision + 10 || y() >= hCollision - 10 || x() <= xCollision -10){
                setPixmap(QPixmap(":/sprites/gauche1.png"));
                setPos(x()-10, y());
            }
            else
                setPixmap(QPixmap(":/sprites/gauche1.png"));
        }

    }

    if(keys[90] == true) // key Z
    {
        if(isColliding() == false)
        {
            setPixmap(QPixmap(":/sprites/derriere1.png"));
            setPos(x(), y()-10);
        }
        else{
            // si on est à gauche                                 droite                          haut
            if(x()+boundingRect().width() <= xCollision + 10 || x() >= wCollision - 10 || y() <= yCollision){
                setPixmap(QPixmap(":/sprites/derriere1.png"));
                setPos(x(), y()-10);
            }
            else
                setPixmap(QPixmap(":/sprites/derriere1.png"));
        }
    }

    if(keys[83] == true) // key S
    {
        if(isColliding() == false)
        {
            setPixmap(QPixmap(":/sprites/devant1.png"));
            setPos(x(), y()+10);
        }
        else{
            // si on est à gauche                                droite                          bas
            if(x()+boundingRect().width() <= xCollision +10 || x() >= wCollision - 10 || y() >= hCollision -10){
                setPixmap(QPixmap(":/sprites/devant1.png"));
                setPos(x(), y()+10);
            }
            else
                setPixmap(QPixmap(":/sprites/devant1.png"));
        }
    }
}

bool Game::isColliding()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Entity)){
            qDebug("PUTAIN CA FAIT MAL ENFOIRE");
            //delete colliding_items[i];
            //delete this;
            xCollision = colliding_items[i]->pos().x();
            yCollision = colliding_items[i]->pos().y();
            wCollision = colliding_items[i]->pos().x() + colliding_items[i]->sceneBoundingRect().width();
            hCollision = colliding_items[i]->pos().y() + colliding_items[i]->sceneBoundingRect().height();

            return true;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Gate))
        {
            qDebug("la tpppppppppppppppppppppp");
            clearLevel();
            level2();
            return true;
        }
    }
    return false;
}

void Game::level1()
{
    Entity *entity1 = new Entity("un premier test", 100, 100, QPixmap(":/sprites/tree.png"));
    Gate *gate = new Gate("gate_grass", 100, 200, QPixmap(":/sprites/door.PNG"));

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    map->getScene()->addItem(gate);
    map->getScene()->addItem(entity1);
    map->getScene()->addItem(this);
    setPos(0, 0);
}

void Game::level2()
{

    map->loadNewBackground(QImage(":/sprites/derriere1.png"));
    Entity *entity2 = new Entity("un premier test", 200, 200, QPixmap(":/sprites/tree.png"));
    Gate *gate2 = new Gate("gate_grass", 400, 200, QPixmap(":/sprites/door.PNG"));

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    map->getScene()->addItem(gate2);
    map->getScene()->addItem(entity2);
    map->getScene()->addItem(this);
    setPos(100, 500);
}

void Game::clearLevel()
{
    //qDebug() << "objets : " << map->getScene()->items(); // ici on affiche les items qu'il y a dans la map
    /*for (int i = 0; i < map->getScene()->items().size() ; i++)
    {
        map->getScene()->removeItem(map->getScene()->items()[0]);

    }
    map->getScene()->removeItem(map->getScene()->items()[0]);*/
    while(!map->getScene()->items().isEmpty())
    {
        map->getScene()->removeItem(map->getScene()->items()[0]);
    }
    //qDebug() << "objets 2 : " << map->getScene()->items(); // ici on affiche les items qui reste
}
