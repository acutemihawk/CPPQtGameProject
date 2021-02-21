#include "Player.h"

Player::Player(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    angle = 0;
    setRotation(angle);
}

Player::~Player()
{

}

QRectF Player::boundingRect() const
{
    return QRectF(-25,-40,50,80);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;

        polygon << QPoint(0,-40) << QPoint(25,40) << QPoint(-25,40);
        painter->setBrush(Qt::red);
        painter->drawPolygon(polygon);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Player::slotGameTimer()
{
    if(GetAsyncKeyState(VK_LEFT)){
        angle = -90;
        setRotation(angle);
        setPos(mapToParent(0, -5));
    }
    if(GetAsyncKeyState(VK_RIGHT)){
        angle = 90;
        setRotation(angle);
        setPos(mapToParent(0, -5));
    }
    if(GetAsyncKeyState(VK_UP)){
        angle = 0;
        setRotation(angle);
        setPos(mapToParent(0, -5));
    }
    if(GetAsyncKeyState(VK_DOWN)){
        angle = 180;
        setRotation(angle);
        setPos(mapToParent(0, -5));
    }

    if(this->x() - 10 < -250){
        this->setX(-240);       // left
    }
    if(this->x() + 10 > 250){
        this->setX(240);        // right
    }

    if(this->y() - 10 < -250){
        this->setY(-240);       // top
    }
    if(this->y() + 10 > 250){
        this->setY(240);        // bottom
    }
}
