#include "item.h"

Item::Item():Entity::Entity()
{

}

Item::Item(QString nameParam, int xParam, int yParam, QPixmap spriteParam):Entity::Entity(name,x,y,sprite)
{
    name = nameParam;
    x = xParam;
    y = yParam;
    sprite = spriteParam;
}

Item::~Item()
{

}
