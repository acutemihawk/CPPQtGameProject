#ifndef NPC_H
#define NPC_H

#include "entity.h"

class Npc : public Entity
{
public:
    Npc();
    Npc(QString nameParam, int xParam, int yParam);
    ~Npc();
};

#endif // NPC_H
