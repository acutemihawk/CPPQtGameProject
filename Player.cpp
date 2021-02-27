#include "player.h"

Player::Player()
{
    setPixmap(QPixmap(":/sprites/character.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    spriteLine = 6; // pixels in the file
    spriteColumn = 1;
    spriteWidth = 15;
    spriteHeight  = 27;
}

Player::~Player()
{

}

void Player::keyPressEvent(QKeyEvent *event)
{
    keys[event->key()] = true;
    movePlayer();
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    keys[event->key()] = false;
}

void Player::movePlayer()
{
    if(keys[68] == true) // key D
    {
        spriteLine = 38;
        updateSprite();
        //setPixmap(QPixmap(":/sprites/droite1.png"));
        setPos(x()+10, y());
    }

    if(keys[81] == true) // key Q
    {
        spriteLine = 102;
        updateSprite();
        //setPixmap(QPixmap(":/sprites/gauche1.png"));
        setPos(x()-10, y());
    }

    if(keys[90] == true) // key Z
    {
        spriteLine = 69;
        updateSprite();
        //setPixmap(QPixmap(":/sprites/derriere1.png"));
        setPos(x(), y()-10);
    }

    if(keys[83] == true) // key S
    {
        spriteLine = 6;
        updateSprite();
        //setPixmap(QPixmap(":/sprites/devant1.png"));
        setPos(x(), y()+10);
    }
}

void Player::updateSprite()
{
    spriteColumn +=16;
    if(spriteColumn >=64)
    {
        spriteColumn =0;
    }
    this->update(-spriteWidth/2,-spriteHeight/2,spriteWidth,spriteHeight);
}

QRectF Player::boundingRect() const
{
    return QRectF(-spriteWidth/2,-spriteHeight/2,spriteWidth,spriteHeight);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-spriteWidth/2,-spriteHeight/2,this->pixmap(),spriteColumn,spriteLine,spriteWidth,spriteHeight);
}
