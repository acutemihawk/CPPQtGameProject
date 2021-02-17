#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(600,600);          /// Defining the size of the widget, ie the window
    this->setFixedSize(600,600);    /// Fix a widget sizes

    scene = new QGraphicsScene();   /// Initialize the graphics scene
    player = new Player();      /// Initialize triangle

    ui->graphicsView->setScene(scene);  /// Set the graphic scene in qgraphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    /// Install anti-aliasing
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Disable scroll vertically
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Disable scroll horizontally

    scene->setSceneRect(-250,-250,500,500); /// Set the graphic scenes

    scene->addLine(-250,0,250,0,QPen(Qt::black));   /// Adding a horizontal line through the center
    scene->addLine(0,-250,0,250,QPen(Qt::black));   /// Add a vertical line through the center

    scene->addLine(-250,-250, 250,-250, QPen(Qt::black));
    scene->addLine(-250, 250, 250, 250, QPen(Qt::black));
    scene->addLine(-250,-250,-250, 250, QPen(Qt::black));
    scene->addLine( 250,-250, 250, 250, QPen(Qt::black));

    scene->addItem(player);   /// Adding to the scene triangle
    player->setPos(0,0);      /// Set the player in the center of the stage

    timer = new QTimer();
    connect(timer, &QTimer::timeout, player, &Player::slotGameTimer);
    timer->start(1000 / 50);
}

Widget::~Widget()
{
    delete ui;
}
