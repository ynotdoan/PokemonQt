#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Headers/player.h"
#include "Headers/collisions.h"

class Game: public QGraphicsView
{
    Q_OBJECT

    void addPlayer();
    void addCollisions();

    QGraphicsScene *scene;
    Player *player;
    Collisions *collisions;

public:
    Game(QWidget *parent = 0);
    ~Game();

    void run();
};

#endif // GAME_H
