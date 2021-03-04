#include "gate.h"

Gate::Gate(QString nameParam, int xParam, int yParam, QPixmap spriteParam, int lvl)
{
    sprite = spriteParam;
    name = nameParam;
    x = xParam;
    y = yParam;
    setPos(x, y);
    setPixmap(spriteParam);
    level = lvl;
    setZValue(level);
}

Gate::~Gate()
{

}

int Gate::getLevel()
{
    return level;
}
