#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>

#include <Player.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

    public:
        explicit Widget(QWidget *parent = 0);
        ~Widget();

    private:
        Ui::Widget      *ui;
        QGraphicsScene  *scene;     /// We declare a graphic scene
        Player        *player;  /// and triangle
        QTimer          *timer;     /* We declare the game a timer,
                                     * by which will be changing the position of an object
                                     * on the stage when exposed to the keyboard keys
                                     * */
};

#endif // WIDGET_H
