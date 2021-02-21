#include "monster.h"


Monster::Monster(QString nameParam, int xParam, int yParam, QPixmap spriteParam, unsigned int healthParam, bool isAliveParam): Entity::Entity(name, x, y, sprite)
{
    name = nameParam;
    x = xParam;
    y = yParam;
    sprite = spriteParam;
    health = healthParam;
    isAlive = isAliveParam;
}

Monster::~Monster()
{

}


unsigned int Monster::getHealth()
{
    return health;
}

void Monster::setHealth(unsigned int value)
{
    health = value;
}

bool Monster::getIsAlive()
{
    return isAlive;
}

void Monster::setIsAlive(bool value)
{
    isAlive = value;
}
