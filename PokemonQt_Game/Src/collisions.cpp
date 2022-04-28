#include <QGraphicsScene>
#include <QPixmap>
#include "Headers/collisions.h"

Collisions::Collisions(QGraphicsScene *scene): QGraphicsPixmapItem()
{
    this->scene = scene;
    QImage image = QImage(":/map/Assets/collision_square.png");
    this->collision_box = this->scene->addPixmap(QPixmap::fromImage(image).scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

Collisions::~Collisions()
{

}
