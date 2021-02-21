#ifndef NPC_H
#define NPC_H

#include <entity.h>

class NPC: public Entity
{
private:
    bool isKillable;
public:
    NPC();
    NPC(QString nameParam, int xParam, int yParam, QPixmap spriteParam,bool isKillableParam);
    ~NPC();
    bool getIsKillable();
    void setIsKillable(bool value);
};

#endif // NPC_H
