#include "gate.h"

Gate::Gate(QString nameParam, int xParam, int yParam, QPixmap spriteParam)
{
    sprite = spriteParam;
    name = nameParam;
    x = xParam;
    y = yParam;
    setPos(x, y);
    setPixmap(spriteParam);
}

Gate::~Gate()
{

}
