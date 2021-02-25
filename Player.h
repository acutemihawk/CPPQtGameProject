#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QMap>

class Player: public QGraphicsRectItem
{
    public:
        Player();
        ~Player();
        void keyPressEvent(QKeyEvent * event);
        void keyReleaseEvent(QKeyEvent *event);
        void movePlayer();
    private:
        QMap<int, bool> keys;
};

#endif // PLAYER_H
