#include "player.h"
#include <iostream>

Player::Player()
{
    setPixmap(QPixmap(":/sprites/devant1.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(0,0);

}

Player::~Player()
{

}

void Player::keyPressEvent(QKeyEvent *event)
{
    keys[event->key()] = true;
    movePlayer();
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    keys[event->key()] = false;
}

void Player::movePlayer()
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

bool Player::isColliding()
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
    }
    return false;
}
