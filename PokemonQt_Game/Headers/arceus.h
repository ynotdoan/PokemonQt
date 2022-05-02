#ifndef ARCEUS_H
#define ARCEUS_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsItem>
#include <vector>

class Arceus: public QObject, public QGraphicsPixmapItem
{
public:
    Arceus(QGraphicsScene *scene);
    ~Arceus();

    void addArceus();

    QGraphicsScene *scene;
    QGraphicsPixmapItem *arc;
};

#endif // ARCEUS_H
