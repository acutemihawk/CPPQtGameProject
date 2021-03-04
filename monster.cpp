#include "monster.h"

Monster::Monster()
{

}

Monster::~Monster()
{

}

Monster::Monster(QString nameParam, int xParam, int yParam, QPixmap spriteParam, int speedParam)
{
    sprite=spriteParam;
    setName(nameParam);
    setX(xParam);
    setY(yParam);
    setPos(x, y);
    setPixmap(spriteParam);
    speed=speedParam;
    xStock=x;
    yStock=y;
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(1000);

}

int Monster::getSpeed()
{
    return speed;
}

void Monster::move()
{
    if(xStock-3*speed<=x && yStock==y)
    {
        setX(x-speed);
        setPos(x,y);
    }
    else if(yStock<=y && y<=yStock+6*speed && x<=xStock-3*speed)
    {
        setY(y+speed);
        setPos(x,y);
    }
    else if(x<=xStock+3*speed && y>=yStock+6*speed)
    {
        setX(x+speed);
        setPos(x,y);
    }
    else if(yStock<=y && x>=x-xStock+3*speed)
    {
        setY(y-speed);
        setPos(x,y);
    }
}

void Monster::playSound()
{

}
