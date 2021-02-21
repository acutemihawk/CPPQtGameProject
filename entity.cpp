#include "entity.h"


Entity::Entity()
{

}

Entity::Entity(QString nameParam, int xParam, int yParam, QPixmap spriteParam)
{
    name = nameParam;
    x = xParam;
    y = yParam;
    sprite = spriteParam;
}

Entity::~Entity()
{

}

QString Entity::getName()
{
    return name;
}

void Entity::setName(QString &value)
{
    name = value;
}

int Entity::getX()
{
    return x;
}

void Entity::setX(int value)
{
    x = value;
}

int Entity::getY()
{
    return y;
}

void Entity::setY(int value)
{
    y = value;
}

QPixmap Entity::getSprite()
{
    return sprite;
}

void Entity::setSprite(QPixmap &value)
{
    sprite = value;
}
