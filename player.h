#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMap>

class Player: public QGraphicsPixmapItem
{
    public:
        Player();
        ~Player();
        void keyPressEvent(QKeyEvent * event);
        void keyReleaseEvent(QKeyEvent *event);
        void movePlayer();
    private:
        QMap<int, bool> keys;
        int forwardIterator = 1;

};

#endif // PLAYER_H
