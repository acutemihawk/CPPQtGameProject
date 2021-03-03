#include "tree.h"

Tree::Tree()
{

}

Tree::Tree(QString nameParam, int xParam, int yParam)

{
    setSprite(QPixmap(":/sprites/tree.png"));
    setName(nameParam);
    setX(xParam);
    setY(yParam);
    setPos(x, y);
}
