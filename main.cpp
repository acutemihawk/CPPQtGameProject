#include <QApplication>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game *myGame = new Game();
    myGame->startGame();

    return a.exec();
}
