#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMap>
#include <QObject>

class Player:public QObject, public QGraphicsPixmapItem
{
        //Q_OBJECT
    public:
        Player(QGraphicsItem * parent=0);
        ~Player();
        void keyPressEvent(QKeyEvent * event);
        void keyReleaseEvent(QKeyEvent *event);
        void movePlayer();
    private:
        QMap<int, bool> keys;
};

#endif // PLAYER_H
