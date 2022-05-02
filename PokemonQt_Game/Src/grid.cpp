#include <QGraphicsScene>
#include <QPixmap>
#include <vector>
#include <QDebug>
#include "Headers/grid.h"

Grid::Grid(QGraphicsScene *scene): QGraphicsPixmapItem()
{
    this->collidable = false; this->encounterable = false;
    this->scene = scene;
    QImage image = QImage(":/map/Assets/collision_square.png");
    this->block = this->scene->addPixmap(QPixmap::fromImage(image).scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

Grid::~Grid()
{
    delete this->scene; delete this->block;
}


void Grid::addGrid()
{
    // Initialize 2d grid vector and insert grid squares
    for (int i = 0; i <= 1600; i+=32) {
        std::vector<Grid*> temp;
        this->grid_blocks.push_back(temp);
    }
    for (int i = 0; i <= 1600; i+=32) {
        for (int j = 0; j <= 1600; j+=32) {
            Grid *block = new Grid(this->scene);
            this->grid_blocks[i/32].push_back(block);
            // Inserts grid blocks onto the map.
            this->grid_blocks[i/32][j/32]->block->setPos(i, j);
            this->scene->addItem(this->grid_blocks[i/32][j/32]);
        }
    }
}

void Grid::addCollisions()
{
/*
    int collision_points[] = {
        1,3,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,39
    };
    for (int i = 0; i < 30; i++) {
        Grid* g = new Grid(this->scene);
        g->block->setPos(32*collision_points[i], 0);
        this->scene->addItem(g);
    }
*/
    this->grid_blocks[49][48]->collidable = true;
    this->grid_blocks[48][48]->collidable = true;
    this->grid_blocks[47][48]->collidable = true;
}
