#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>
#include "Headers/player.h"
#include "Headers/grid.h"
#include "Headers/arceus.h"

class Game: public QGraphicsView
{
    Q_OBJECT

    QGraphicsScene *scene;
    Player *player;
    Grid *grid;
    Arceus *arc;
    std::vector< std::vector<Grid*> > grid_blocks;

public:
    Game(QWidget *parent = 0);
    ~Game();

    void setMap();
    void run();
};

#endif // GAME_H
