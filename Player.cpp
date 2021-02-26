#include "player.h"

Player::Player()
{
    setPixmap(QPixmap(":/sprites/devant1.png"));
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
}

void Player::movePlayer()
{
    if(keys[68] == true) // key D
    {
        setPixmap(QPixmap(":/sprites/droite1.png"));
        setPos(x()+10, y());
    }

    if(keys[81] == true) // key Q
    {
        setPixmap(QPixmap(":/sprites/gauche1.png"));
        setPos(x()-10, y());
    }

    if(keys[90] == true) // key Z
    {
        setPixmap(QPixmap(":/sprites/derriere1.png"));
        setPos(x(), y()-10);
    }

    if(keys[83] == true) // key S
    {
        setPixmap(QPixmap(":/sprites/devant1.png"));
        setPos(x(), y()+10);
    }

}
