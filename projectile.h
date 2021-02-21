#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <entity.h>

class Projectile : public Entity
{
protected:
    bool isActive;
    int speed;
public:
    Projectile();
    Projectile(QString nameParam, int xParam, int yParam, QPixmap spriteParam, bool isActiveParam,int speedParam);
    ~Projectile();
    bool getIsActive();
    void setIsActive(bool value);
    int getSpeed();
    void setSpeed(int value);
};

#endif // PROJECTILE_H
