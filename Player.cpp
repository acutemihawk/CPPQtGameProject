#include "player.h"

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
    if(keys[68] == true && directionColliding[68] == false) // key D
    {
        if(isColliding() == false)
        {
            setPixmap(QPixmap(":/sprites/droite1.png"));
            setPos(x()+10, y());
            directionColliding[68] = false;
        }
        else{
            directionColliding[68] = true;
        }
    }

    if(keys[81] == true && directionColliding[81] == false) // key Q
    {
        if(isColliding() == false)
        {
            setPixmap(QPixmap(":/sprites/gauche1.png"));
            setPos(x()-10, y());
            directionColliding[81] = false;
        }
        else{
            directionColliding[81] = true;
        }

    }

    if(keys[90] == true && directionColliding[90] == false) // key Z
    {
        if(isColliding() == false)
        {
            setPixmap(QPixmap(":/sprites/derriere1.png"));
            setPos(x(), y()-10);
            directionColliding[90] = false;
        }
        else{
            directionColliding[90] = true;
        }

    }

    if(keys[83] == true && directionColliding[83] == false) // key S
    {
        if(isColliding() == false)
        {
            setPixmap(QPixmap(":/sprites/devant1.png"));
            setPos(x(), y()+10);
            directionColliding[83] = false;
        }
        else{
            directionColliding[83] = true;
        }

    }


}

bool Player::isColliding()
{
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
    QKeyEvent *event;

    //if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Entity)){
            qDebug("AAAAAAAAAAAAAAAAAAAAIE" + 1);
            // delete them from the heap to save memory
            //delete colliding_items[i];
            //delete this;
            directionColliding[event->key()] = true;
            // return (all code below refers to a non existint bullet)
            return true;
        }
    }
    return false;
}
