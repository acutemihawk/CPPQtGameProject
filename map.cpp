#include "map.h"

Map::Map(QImage image)
{
    view = new QGraphicsView();
    scene = new QGraphicsScene();

    // window settup
    view->setWindowIcon(QIcon(":/sprites/icon.png"));
    view->setWindowTitle("Zeldo");
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(700, 700);

    // in-game window setup
    view->setBackgroundBrush(QBrush(QImage(":/sprites/bg.png")));
    view->setSceneRect(0, 0, 700,700);
    scene->setStickyFocus(true);
    view->setScene(scene);
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
    return view->scene();
}

void Map::setScene(QGraphicsScene *newValue)
{
    view->setScene(newValue);
}
