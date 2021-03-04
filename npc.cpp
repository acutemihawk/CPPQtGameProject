#include "npc.h"

Npc::Npc()
{

}

Npc::Npc(QString nameParam, int xParam, int yParam)

{
    setSprite(QPixmap(":/sprites/npc.png"));
    setName(nameParam);
    setX(xParam);
    setY(yParam);
    setPos(x, y);
}

Npc::~Npc()
{

}
