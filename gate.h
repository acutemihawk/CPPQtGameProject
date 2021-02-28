#ifndef GATE_H
#define GATE_H

#include <entity.h>
#include <QGraphicsView>

class Gate: public Entity
{
    private :
        QImage imageNewMap;
    public:
        Gate(QString nameParam, int xParam, int yParam, QPixmap spriteParam,QImage image);
        ~Gate();
        QImage getImageNewMap();
        void setImageNewMap(QImage image);
};

#endif // GATE_H
