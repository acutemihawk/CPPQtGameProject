#include "npc.h"

Npc::Npc()
{

}

Npc::Npc(QString nameParam, int xParam, int yParam, QPixmap spriteParam)

{
    sprite = spriteParam;
    name = nameParam;
    x = xParam;
    y = yParam;
    setPos(x, y);
    setPixmap(spriteParam);
}

Npc::~Npc()
{

}
