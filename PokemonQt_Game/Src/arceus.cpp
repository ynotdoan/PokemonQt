#include <QGraphicsScene>
#include <QPixmap>
#include "Headers/arceus.h"

Arceus::Arceus(QGraphicsScene *scene): QGraphicsPixmapItem()
{
    this->scene = scene;
    QImage image = QImage(":/chars/Assets/arceus1.png");
    this->arc = this->scene->addPixmap(QPixmap::fromImage(image).scaled(96, 96, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

Arceus::~Arceus()
{
    delete this->scene; delete this->arc;
}

void Arceus::addArceus()
{
    this->arc->setPos(32*34, 32*1);
    this->scene->addItem(this);
}
