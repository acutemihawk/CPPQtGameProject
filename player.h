#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMap>
#include <QPainter>

class Player: public QObject, public QGraphicsPixmapItem
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


        //everything needed form player animations
        float spriteLine, spriteColumn;
        int spriteWidth;
        int spriteHeight;

        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void updateSprite();
};

#endif // PLAYER_H
