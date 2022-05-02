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
    void checkEncounter();

    QPixmap map;
    QGraphicsScene *scene;
    Sprite *sprite;

public:
    Player(QGraphicsScene *scene);
    ~Player();

    void addPlayer();
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
