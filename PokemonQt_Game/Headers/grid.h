#ifndef GRID_H
#define GRID_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsItem>
#include <vector>
#include "Headers/sprite.h"

class Grid: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    QPixmap map;
    QGraphicsScene *scene;
    bool collidable, encounterable;
    std::vector< std::vector<Grid*> > grid_blocks;

public:
    Grid();
    Grid(QGraphicsScene *scene);
    ~Grid();

    void setCollideable(std::vector< std::vector<Grid*> > &g);
    void setEncounterable(std::vector< std::vector<Grid*> > &g);
    void addGrid();

    QGraphicsPixmapItem *block;
};

#endif // GRID_H
