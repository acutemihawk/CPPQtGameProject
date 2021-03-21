#ifndef DIALOG_H
#define DIALOG_H

#include <QPainter>
#include <QGraphicsItem>

class Dialog : public QGraphicsItem
{
public:
    Dialog();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Dialog();

};

#endif // DIALOG_H
