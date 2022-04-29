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

    QPixmap map;
    QGraphicsScene *scene;
    Sprite *sprite;
    int x_pos, y_pos;

public:
    Player(QGraphicsScene *scene);
    ~Player();

    void addPlayer();
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
