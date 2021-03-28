#include "gamecontroller.h"
#include <QDebug>

GameController::GameController()
{
    music = new QMediaPlayer();
    musicEffect = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/soliloquy.wav"));
    music->setVolume(8);
    music->play();

    musicEffect = new QMediaPlayer();
    musicEffect->setMedia(QUrl("qrc:/sounds/teleport.wav"));
    musicEffect->setVolume(9);

    dialog = new Dialog("Un arbre qui parle on sait pas pourquoi : \n BORDEL C'EST PAS PARCE QUE JE SUIS UN ARBRE QUE TU DOIS \n ME RENTRER DEDANS!");

    lastDirection = 1;
    map =new Map(QImage(":/sprites/bg.png"));
    setPixmap(QPixmap(":/sprites/devant1.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(0,0);
}

GameController::~GameController()
{

}

void GameController::startGame()
{
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setYOffset(-5);
    setGraphicsEffect(shadow);

    //QGraphicsBlurEffect *blur = new QGraphicsBlurEffect();
    //blur->setBlurRadius(1.25);

    //QGraphicsOpacityEffect *opa = new QGraphicsOpacityEffect();
    //opa->setOpacity(0.2);

    //here is the menu page when we start the game

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
        if(x() + 30 < 1200)
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
        else
            setPixmap(QPixmap(":/sprites/droite1.png"));
    }

    if(keys[81] == true || keys[37] == true) // key Q
    {
        if(x() > 0)
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
        else
            setPixmap(QPixmap(":/sprites/gauche1.png"));
    }

    if(keys[90] == true || keys[38] == true) // key Z
    {
        if(y() > 0)
        {
            if(isColliding() == false)
            {
                /*music->setMedia(QUrl("qrc:/sounds/step_grass.wav"));
                music->play();*/
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
        else
            setPixmap(QPixmap(":/sprites/derriere1.png"));
    }

    if(keys[83] == true || keys[40] == true) // key S
    {
        if(y() + 45 < 700)
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
        else
            setPixmap(QPixmap(":/sprites/devant1.png"));
    }

    if(keys[32] == true) // key spacebar
    {
        dialog->hide();
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
            musicEffect->play();
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
        else if (typeid(*(colliding_items[i]))==typeid(Monster))
        {
            delete colliding_items[i];
        }
    }
    return false;
}

void GameController::level1()
{
    map->loadNewBackground(QImage(":/sprites/bg.png"));

    Tree *tree1 = new Tree("un premier test", 0, 0);
    Tree *tree2 = new Tree("un premier test", 75, 0);
    Tree *tree3 = new Tree("un premier test", 150, 0);
    Tree *tree4 = new Tree("un premier test", 225, 0);
    Tree *tree5 = new Tree("un premier test", 300, 0);
    Tree *tree6 = new Tree("un premier test", 375, 0);
    Tree *tree7 = new Tree("un premier test", 450, 0);
    Tree *tree8 = new Tree("un premier test", 525, 0);
    Tree *tree9 = new Tree("un premier test", 600, 0);
    Tree *tree10 = new Tree("un premier test", 0, 75);
    Tree *tree11 = new Tree("un premier test", 0, 150);
    Tree *tree12 = new Tree("un premier test", 0, 225);
    Tree *tree13 = new Tree("un premier test", 0, 300);
    Tree *tree14 = new Tree("un premier test", 0, 375);
    Tree *tree15 = new Tree("un premier test", 0, 450);
    Tree *tree16 = new Tree("un premier test", 0, 525);
    Tree *tree17 = new Tree("un premier test", 0, 600);
    Tree *tree18 = new Tree("un premier test", 600, 75);
    Tree *tree19 = new Tree("un premier test", 600, 150);
    Tree *tree20 = new Tree("un premier test", 600, 225);
    Tree *tree21 = new Tree("un premier test", 600, 300);
    Tree *tree22 = new Tree("un premier test", 600, 375);
    Tree *tree23 = new Tree("un premier test", 600, 450);
    Tree *tree24 = new Tree("un premier test", 600, 525);
    Tree *tree25 = new Tree("un premier test", 600, 600);
    Tree *tree26 = new Tree("un premier test", 600, 600);
    Tree *tree27 = new Tree("un premier test", 75, 600);
    Tree *tree28 = new Tree("un premier test", 150, 600);
    Tree *tree29 = new Tree("un premier test", 225, 600);
    Tree *tree30 = new Tree("un premier test", 300, 600);
    Tree *tree31 = new Tree("un premier test", 375, 600);
    Tree *tree32 = new Tree("un premier test", 450, 600);
    Tree *tree33 = new Tree("un premier test", 525, 600);

    Gate *gate = new Gate("gate_grass", 100, 200, QPixmap(":/sprites/door.png"), 2);
    Monster *monster1 = new Monster("Godzilla", 300,300,QPixmap(":/sprites/monstre.png"), 30);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    map->getScene()->addItem(tree1);
    map->getScene()->addItem(tree2);
    map->getScene()->addItem(tree3);
    map->getScene()->addItem(tree4);
    map->getScene()->addItem(tree5);
    map->getScene()->addItem(tree6);
    map->getScene()->addItem(tree7);
    map->getScene()->addItem(tree8);
    map->getScene()->addItem(tree9);
    map->getScene()->addItem(tree10);
    map->getScene()->addItem(tree11);
    map->getScene()->addItem(tree12);
    map->getScene()->addItem(tree13);
    map->getScene()->addItem(tree14);
    map->getScene()->addItem(tree15);
    map->getScene()->addItem(tree16);
    map->getScene()->addItem(tree17);
    map->getScene()->addItem(tree18);
    map->getScene()->addItem(tree19);
    map->getScene()->addItem(tree20);
    map->getScene()->addItem(tree21);
    map->getScene()->addItem(tree22);
    map->getScene()->addItem(tree23);
    map->getScene()->addItem(tree24);
    map->getScene()->addItem(tree25);
    map->getScene()->addItem(tree26);
    map->getScene()->addItem(tree27);
    map->getScene()->addItem(tree28);
    map->getScene()->addItem(tree29);
    map->getScene()->addItem(tree30);
    map->getScene()->addItem(tree31);
    map->getScene()->addItem(tree32);
    map->getScene()->addItem(tree33);

    map->getScene()->addItem(dialog);
    dialog->hide();
    map->getScene()->addItem(gate);
    map->getScene()->addItem(monster1);
    map->getScene()->addItem(this);
    setPos(500, 500);
}

void GameController::level2()
{

    map->loadNewBackground(QImage(":/sprites/bg.png"));

    Tree *tree1 = new Tree("un premier test", 0, 0);
    Tree *tree2 = new Tree("un premier test", 75, 0);
    Tree *tree3 = new Tree("un premier test", 150, 0);
    Tree *tree4 = new Tree("un premier test", 225, 0);
    Tree *tree5 = new Tree("un premier test", 300, 0);
    Tree *tree6 = new Tree("un premier test", 375, 0);
    Tree *tree7 = new Tree("un premier test", 450, 0);
    Tree *tree8 = new Tree("un premier test", 525, 0);
    Tree *tree9 = new Tree("un premier test", 600, 0);
    Tree *tree10 = new Tree("un premier test", 0, 75);
    Tree *tree11 = new Tree("un premier test", 0, 150);
    Tree *tree12 = new Tree("un premier test", 0, 225);
    Tree *tree13 = new Tree("un premier test", 0, 300);
    Tree *tree14 = new Tree("un premier test", 0, 375);
    Tree *tree15 = new Tree("un premier test", 0, 450);
    Tree *tree16 = new Tree("un premier test", 0, 525);
    Tree *tree17 = new Tree("un premier test", 0, 600);
    Tree *tree18 = new Tree("un premier test", 600, 75);
    Tree *tree19 = new Tree("un premier test", 600, 150);
    Tree *tree20 = new Tree("un premier test", 600, 225);
    Tree *tree21 = new Tree("un premier test", 600, 300);
    Tree *tree22 = new Tree("un premier test", 600, 375);
    Tree *tree23 = new Tree("un premier test", 600, 450);
    Tree *tree24 = new Tree("un premier test", 600, 525);
    Tree *tree25 = new Tree("un premier test", 600, 600);
    Tree *tree26 = new Tree("un premier test", 600, 600);
    Tree *tree27 = new Tree("un premier test", 75, 600);
    Tree *tree28 = new Tree("un premier test", 150, 600);
    Tree *tree29 = new Tree("un premier test", 225, 600);
    Tree *tree30 = new Tree("un premier test", 300, 600);
    Tree *tree31 = new Tree("un premier test", 375, 600);
    Tree *tree32 = new Tree("un premier test", 450, 600);
    Tree *tree33 = new Tree("un premier test", 525, 600);

    Gate *gate2 = new Gate("gate_grass", 400, 200, QPixmap(":/sprites/door.png"), 1);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    map->getScene()->addItem(tree1);
    map->getScene()->addItem(tree2);
    map->getScene()->addItem(tree3);
    map->getScene()->addItem(tree4);
    map->getScene()->addItem(tree5);
    map->getScene()->addItem(tree6);
    map->getScene()->addItem(tree7);
    map->getScene()->addItem(tree8);
    map->getScene()->addItem(tree9);
    map->getScene()->addItem(tree10);
    map->getScene()->addItem(tree11);
    map->getScene()->addItem(tree12);
    map->getScene()->addItem(tree13);
    map->getScene()->addItem(tree14);
    map->getScene()->addItem(tree15);
    map->getScene()->addItem(tree16);
    map->getScene()->addItem(tree17);
    map->getScene()->addItem(tree18);
    map->getScene()->addItem(tree19);
    map->getScene()->addItem(tree20);
    map->getScene()->addItem(tree21);
    map->getScene()->addItem(tree22);
    map->getScene()->addItem(tree23);
    map->getScene()->addItem(tree24);
    map->getScene()->addItem(tree25);
    map->getScene()->addItem(tree26);
    map->getScene()->addItem(tree27);
    map->getScene()->addItem(tree28);
    map->getScene()->addItem(tree29);
    map->getScene()->addItem(tree30);
    map->getScene()->addItem(tree31);
    map->getScene()->addItem(tree32);
    map->getScene()->addItem(tree33);

    map->getScene()->addItem(dialog);
    dialog->hide();
    map->getScene()->addItem(gate2);
    map->getScene()->addItem(this);
    setPos(500, 500);
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

