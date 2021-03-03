#ifndef GATE_H
#define GATE_H

#include <entity.h>
#include <QGraphicsView>

class Gate: public Entity
{
    public:
        Gate(QString nameParam, int xParam, int yParam, QPixmap spriteParam);
        ~Gate();
};

#endif // GATE_H
