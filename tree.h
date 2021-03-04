#ifndef TREE_H
#define TREE_H

#include "entity.h"

class Tree : public Entity
{
public:
    Tree();
    Tree(QString nameParam, int xParam, int yParam, QPixmap spriteParam);
    ~Tree();
};

#endif // TREE_H
