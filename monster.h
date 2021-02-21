#ifndef MONSTER_H
#define MONSTER_H

#include "entity.h"

class Monster : public Entity
{
    protected:
        unsigned int health;
        bool isAlive;
    public:
        Monster(QString nameParam, int xParam, int yParam, QPixmap spriteParam, unsigned int healthParam, bool isAliveParam);
        Monster();
        ~Monster();
        unsigned int getHealth();
        void setHealth(unsigned int value);
        bool getIsAlive();
        void setIsAlive(bool value);
};

#endif // MONSTER_H
