#include "Player.h"
#include <iostream>

Player::Player()
{
    setPixmap(QPixmap(":/sprites/devant1.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(0,0);
    colliding_items = collidingItems();
}

Player::~Player()
{

}

int Player::getXCollision()
{
    return xCollision;
}

void Player::setXCollision(int value)
{
    xCollision = value;
}

int Player::getYCollision()
{
    return yCollision;
}

void Player::setYCollision(int value)
{
    yCollision = value;
}

QMap<int, bool> Player::getKeys()
{
    return keys;
}

void Player::setKeys(QMap<int, bool> &value)
{
    keys = value;
}

void Player::setPixMap(QPixmap pixmap)
{
    setPixmap(pixmap);
}

void Player::setPosition(int x,int y)
{
    setPos(x,y);
}

qreal Player::getX()
{
    return x();
}

qreal Player::getY()
{
    return y();
}

QList<QGraphicsItem *> Player::getColliding_items()
{
    return colliding_items;
}

void Player::setColliding_items(QList<QGraphicsItem *> &value)
{
    colliding_items = value;
}

