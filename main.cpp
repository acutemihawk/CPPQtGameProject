#include <QApplication>
#include "gamecontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameController *myGame = new GameController();
    myGame->startGame();

    return a.exec();
}
