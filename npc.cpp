#include "npc.h"

NPC::NPC()
{

}

NPC::NPC(QString nameParam, int xParam, int yParam, QPixmap spriteParam,bool isKillableParam)
{
    Entity(nameParam,xParam,yParam,spriteParam);
    isKillable=isKillableParam;
}

bool NPC::getIsKillable()
{
    return isKillable;
}

void NPC::setIsKillable(bool value)
{
    isKillable = value;
}


