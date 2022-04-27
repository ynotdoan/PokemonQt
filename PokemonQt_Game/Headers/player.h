#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "Headers/sprite.h"

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    QPixmap map;
    QGraphicsScene *scene;
    Sprite *sprite;

public:
    Player(QGraphicsScene *scene);
    ~Player();

    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
