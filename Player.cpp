#include "player.h"

Player::Player()
{
    setPixmap(QPixmap(":/ressources/prites/Tiny16MaleSprites.png"));
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
        setPos(x()+20, y());
    }

    if(keys[81] == true) // key Q
    {
        setPos(x()-20, y());
    }

    if(keys[90] == true) // key Z
    {
        setPos(x(), y()-20);
    }

    if(keys[83] == true) // key S
    {
        setPos(x(), y()+20);
    }

}
