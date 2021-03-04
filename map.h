#ifndef MAP_H
#define MAP_H

#include <QGraphicsView>
#include <QIcon>

class Map
{
    private:
        QGraphicsView *view;
        QGraphicsScene *scene;
    public:
        Map(QImage image);
        ~Map();
        void loadNewBackground(QImage image);
        QGraphicsView *getView();
        void setView(QGraphicsView *newView);
        QGraphicsScene *getScene();
        void setScene(QGraphicsScene *newScene);
};

#endif // MAP_H
