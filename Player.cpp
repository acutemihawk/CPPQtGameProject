#include "player.h"

Player::Player()
{
    setRect(0,0,10,50);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
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
    movePlayer();
}

void Player::movePlayer()
{
    /*if(event->key() == Qt::Key_D)
    {
        if(keys[90] == true) // key Z
        {
            setPos(x()+10, y()-10);
        }
        else if(keys[83] == true) // key S
        {
            setPos(x()+10, y()+10);
        }
        else
        {
            setPos(x()+10, y());
        }
    }

    if(event->key() == Qt::Key_Q)
    {
        if(keys[90] == true) // key Z
        {
            setPos(x()-10, y()-10);
        }
        else if(keys[83] == true) // key S
        {
            setPos(x()-10, y()+10);
        }
        else
        {
            setPos(x()-10, y());
        }
    }

    if(event->key() == Qt::Key_Z)
    {
        if(keys[68] == true) // key D
        {
            setPos(x()+10, y()-10);
        }
        else if(keys[81] == true) // key Q
        {
            setPos(x()-10, y()-10);
        }
        else
        {
            setPos(x(), y()-10);
        }
    }

    if(event->key() == Qt::Key_S)
    {
        if(keys[68] == true) // key D
        {
            setPos(x()+10, y()+10);
        }
        else if(keys[81] == true) // key Q
        {
            setPos(x()-10, y()+10);
        }
        else
        {
            setPos(x(), y()+10);
        }
    }*/

    if(keys[68] == true) // key D
    {
        setPos(x()+10, y());
    }

    if(keys[81] == true) // key Q
    {
        setPos(x()-10, y());
    }

    if(keys[90] == true) // key Z
    {
        setPos(x(), y()-10);
    }

    if(keys[83] == true) // key S
    {
        setPos(x(), y()+10);
    }
}
