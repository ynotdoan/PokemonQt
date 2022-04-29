#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>
#include "Headers/player.h"
#include "Headers/grid.h"

class Game: public QGraphicsView
{
    Q_OBJECT

    bool collides();

    QGraphicsScene *scene;
    Player *player;
    Grid *grid;
    std::vector< std::vector<Grid*> > grid_blocks;

public:
    Game(QWidget *parent = 0);
    ~Game();

    void setMap();
    void run();
};

#endif // GAME_H
