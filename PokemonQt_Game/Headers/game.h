#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Headers/player.h"

class Game: public QGraphicsView
{
    Q_OBJECT

    void addPlayer();

    QGraphicsScene *scene;
    Player *player;

public:
    Game(QWidget *parent = 0);
    ~Game();

    void run();
};

#endif // GAME_H
