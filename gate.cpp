#include "gate.h"

Gate::Gate(QString nameParam, int xParam, int yParam, QPixmap spriteParam,QImage image)
{
    sprite = spriteParam;
    name = nameParam;
    x = xParam;
    y = yParam;
    setPos(x, y);
    setPixmap(spriteParam);
    imageNewMap=image;
}

Gate::~Gate()
{

}

QImage Gate::getImageNewMap()
{
    return imageNewMap;
}

void Gate::setImageNewMap(QImage image)
{
    imageNewMap = image;
}
