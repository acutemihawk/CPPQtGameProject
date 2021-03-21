#include "dialog.h"

Dialog::Dialog()
{

}

QRectF Dialog::boundingRect() const
{
    return QRectF(50, 500, 500, 90);
}

void Dialog::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 5);
    painter->setPen(pen);
    painter->drawRect(rect);
    painter->fillRect(rect, Qt::blue);

    QRectF rectInside = QRectF(90, 505, 400, 80);
    painter->drawRect(rectInside);
    painter->fillRect(rectInside, Qt::white);
    painter->drawText(rectInside, Qt::AlignCenter, "Je suis injouable !");
}

Dialog::~Dialog()
{
}
