#include "gamecontroller.h"
#include <QDebug>

GameController::GameController()
{
    lastDirection = 1;
    map =new Map(QImage(":/sprites/bg.png"));
    setPixmap(QPixmap(":/sprites/devant1.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(0,0);
    dialog = new Dialog("Un arbre qui parle on sait pas pourquoi : \n BORDEL C'EST PAS PARCE QUE JE SUIS UN ARBRE QUE TU DOIS \n ME RENTRER DEDANS!");

}

GameController::~GameController()
{

}

void GameController::startGame()
{
    /*QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setYOffset(-5);

    //QGraphicsBlurEffect *blur = new QGraphicsBlurEffect();
    //blur->setBlurRadius(1.25);

    //QGraphicsOpacityEffect *opa = new QGraphicsOpacityEffect();
    //opa->setOpacity(0.2);

    player->setGraphicsEffect(shadow);*/

    level1();
}

void GameController::keyPressEvent(QKeyEvent *event)
{
    keys[event->key()] = true;
    movePlayer();
}

void GameController::keyReleaseEvent(QKeyEvent *event)
{
    keys[event->key()] = false;
}

void GameController::movePlayer()
{
    if(keys[68] == true || keys[39] == true) // key D
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
        lastDirection = 4;
    }

    if(keys[81] == true || keys[37] == true) // key Q
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
        lastDirection = 2;
    }

    if(keys[90] == true || keys[38] == true) // key Z
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
        lastDirection = 3;
    }

    if(keys[83] == true || keys[40] == true) // key S
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
        lastDirection = 1;
    }

    if(keys[32] == true) // key spacebar
    {
        switch(lastDirection)
        {
            case 1:
                setPixmap(QPixmap(":/sprites/epeedevant.png"));
                break;
            case 2:
                setPixmap(QPixmap(":/sprites/epeegauche.png"));
                break;
            case 3:
                setPixmap(QPixmap(":/sprites/epeederriere.png"));
                break;
            case 4:
                setPixmap(QPixmap(":/sprites/epeedroite.png"));
                break;
        }
    }

    if(keys[Qt::Key_Escape] == true) // escape key to close the dialog
    {
        dialog->hide();
    }

}

bool GameController::isColliding()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Tree)){
            qDebug("PUTAIN CA FAIT MAL ENFOIRE");
            xCollision = colliding_items[i]->pos().x();
            yCollision = colliding_items[i]->pos().y();
            wCollision = colliding_items[i]->pos().x() + colliding_items[i]->sceneBoundingRect().width();
            hCollision = colliding_items[i]->pos().y() + colliding_items[i]->sceneBoundingRect().height();
            dialog->show();

            return true;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Gate))
        {
            switch((int)colliding_items[i]->zValue())
            {
                case 1:
                    clearLevel();
                    level1();
                    break;
                case 2:
                    clearLevel();
                    level2();
                    break;
            }

            return true;
        }
    }
    return false;
}

void GameController::level1()
{
    map->loadNewBackground(QImage(":/sprites/bg.png"));
    //Entity *entity1 = new Entity("un premier test", 100, 100, QPixmap(":/sprites/tree.png"));
    Gate *gate = new Gate("gate_grass", 100, 200, QPixmap(":/sprites/door.png"), 2);
    Tree *tree = new Tree("arbre", 400, 300, QPixmap(":sprites/tree.png"));

    map->getScene()->addItem(dialog);
    dialog->hide();

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    map->getScene()->addItem(gate);

    //map->getScene()->addItem(entity1);
    map->getScene()->addItem(tree);
    map->getScene()->addItem(this);
    setPos(0, 0);
}

void GameController::level2()
{

    map->loadNewBackground(QImage(":/sprites/derriere1.png"));
    Tree *tree2 = new Tree("un premier test", 200, 200, QPixmap(":/sprites/tree.png"));
    Gate *gate2 = new Gate("gate_grass", 400, 200, QPixmap(":/sprites/door.png"), 1);
    map->getScene()->addItem(dialog);
    dialog->hide();

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    map->getScene()->addItem(gate2);
    map->getScene()->addItem(tree2);
    map->getScene()->addItem(this);
    setPos(100, 500);
}

void GameController::clearLevel()
{
    //qDebug() << "objets : " << map->getScene()->items(); // ici on affiche les items qu'il y a dans la map
    while(!map->getScene()->items().isEmpty())
    {
        map->getScene()->removeItem(map->getScene()->items()[0]);
    }
    //qDebug() << "objets 2 : " << map->getScene()->items(); // ici on affiche les items qui reste
}
