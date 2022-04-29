#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "Headers/sprite.h"
#include "Headers/grid.h"

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    bool checkVerticalBounds();
    bool checkHorizontalBounds();
    bool checkCollision();

    QPixmap map;
    QGraphicsScene *scene;
    Sprite *sprite;
    int x_pos, y_pos;

public:
    Player(QGraphicsScene *scene);
    ~Player();

    void addPlayer();
    void keyPressEvent(QKeyEvent *event);

    Grid *g;
    Grid *g2;
};

#endif // PLAYER_H
