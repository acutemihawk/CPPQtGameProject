#ifndef GATE_H
#define GATE_H

#include <entity.h>
#include <QGraphicsView>

class Gate: public Entity
{
    private:
        int level;
    public:
        Gate(QString nameParam, int xParam, int yParam, QPixmap spriteParam, int lvl);
        ~Gate();
        int getLevel();
};

#endif // GATE_H
