#ifndef DIALOG_H
#define DIALOG_H

#include <QPainter>
#include <QGraphicsItem>

class Dialog : public QGraphicsItem
{
private:
    QString npcScript;
public:
    Dialog();
    Dialog(QString script);
    ~Dialog();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setScript(QString npcScript);
    QString getScript();
};

#endif // DIALOG_H
