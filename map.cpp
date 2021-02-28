#include "map.h"

Map::Map(QImage image)
{
    view = new QGraphicsView();
    scene = new QGraphicsScene();
    view->setBackgroundBrush(QBrush(image));
    view->setScene(scene);
    view->setWindowTitle("Zeldo");
    view->setFixedSize(1280, 720);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
}

Map::~Map()
{
    free(view);
    free(scene);
}

void Map::loadNewBackground(QImage image)
{
    view->setBackgroundBrush(QBrush(image));
}

QGraphicsView *Map::getView()
{
    return view;
}

void Map::setView(QGraphicsView *newValue)
{
    view = newValue;
}

QGraphicsScene *Map::getScene()
{
    return scene;
}

void Map::setScene(QGraphicsScene *newValue)
{
    scene = newValue;
}


