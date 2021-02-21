#ifndef ENTITY_H
#define ENTITY_H

#include <QString>
#include <QGraphicsPixmapItem>

class Entity
{
private:
    QString name;
    int x;
    int y;
    QPixmap sprite;
public:
    Entity();
    Entity(QString nameParam, int xParam, int yParam, QPixmap spriteParam);
    ~Entity();

    QString getName();
    void setName(QString &value);
    int getX();
    void setX(int value);
    int getY();
    void setY(int value);
    QPixmap getSprite();
    void setSprite(QPixmap &value);
};

#endif // ENTITY_H
