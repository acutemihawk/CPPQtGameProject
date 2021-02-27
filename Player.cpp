#include "Player.h"
#include <iostream>

Player::Player()
{
    setPixmap(QPixmap(":/sprites/devant1.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(0,0);
    directionColliding[68] = false;
    directionColliding[81] = false;
    directionColliding[90] = false;
    directionColliding[83] = false;
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
            if(x() > xCollision - 5){
                setPixmap(QPixmap(":/sprites/droite1.png"));
                setPos(x()+10, y());
            }
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
            if(x() - 5 < xCollision){
                setPixmap(QPixmap(":/sprites/gauche1.png"));
                setPos(x()-10, y());
            }
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
            if(y() - 5 < yCollision){
                setPixmap(QPixmap(":/sprites/derriere1.png"));
                setPos(x(), y()-10);
            }
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
            if(y() > yCollision - 5){
                setPixmap(QPixmap(":/sprites/devant1.png"));
                setPos(x(), y()+10);
            }
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
            return true;
        }
    }
    return false;
}

