#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsItem>
#include "Headers/sprite.h"

class Collisions: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    QPixmap map;
    QGraphicsScene *scene;

public:
    Collisions(QGraphicsScene *scene);
    ~Collisions();

    QGraphicsPixmapItem *collision_box;
};

#endif // COLLISIONS_H
