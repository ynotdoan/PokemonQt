#include <iostream>
#include <QApplication>

#include "Headers/game.h"

int main(int argc, char **argv)
{
    // New QApplication.
    QApplication app(argc, argv);
    // New Game instance g.
    Game g;
    // Runs the game.
    g.run();
    // Executing QApplication to run.
    return app.exec();
}
