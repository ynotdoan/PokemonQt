#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Headers/game.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Game *g = new Game();

    g->run();
    return app.exec();
}
