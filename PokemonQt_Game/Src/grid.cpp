#include <QGraphicsScene>
#include <QPixmap>
#include <vector>
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

void Grid::setCollideable(std::vector< std::vector<Grid*> > &g)
{
    std::pair<int, int> collidable_objs[] = {
        std::make_pair(0, 1), std::make_pair(0, 3), std::make_pair(0, 11)
    };
    g[49][45]->collidable = true;
}

void Grid::setEncounterable(std::vector< std::vector<Grid*> > &g)
{

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
