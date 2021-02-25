#include "projectile.h"

Projectile::Projectile():Entity::Entity()
{

}

Projectile::Projectile(QString nameParam, int xParam, int yParam, QPixmap spriteParam, bool isActiveParam,int speedParam):Entity::Entity(name,x,y,sprite)
{
    name = nameParam;
    x = xParam;
    y = yParam;
    sprite = spriteParam;
    isActive=isActiveParam;
    speed=speedParam;
}

int Projectile::getSpeed()
{
    return speed;
}

void Projectile::setSpeed(int value)
{
    speed = value;
}

bool Projectile::getIsActive()
{
    return isActive;
}

void Projectile::setIsActive(bool value)
{
    isActive = value;
}
