#include "tree.h"

Tree::Tree()
{

}

Tree::Tree(QString nameParam, int xParam, int yParam, QPixmap spriteParam)
{
    sprite = spriteParam;
    name = nameParam;
    x = xParam;
    y = yParam;
    setPos(x, y);
    setPixmap(spriteParam);
}

Tree::~Tree()
{

}
