#ifndef MONSTER_H
#define MONSTER_H

#include <entity.h>
#include <QTimer>

class Monster: public QObject,public Entity
{
    Q_OBJECT
    private:
        int speed;
        QTimer *timer;
        int xStock;
        int yStock;
    public:
        Monster();
        ~Monster();
        Monster(QString nameParam, int xParam, int yParam, QPixmap spriteParam,int speedParam);
        int getSpeed();
        void playSound();
    public slots:
        void move();
};

#endif // MONSTER_H
