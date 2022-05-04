#include <QTimer>
#include <QWidget>
#include <QGraphicsScene>
#include <QPixmap>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include "Headers/grid.h"

#include <iostream>

Grid::Grid(QGraphicsScene *scene): QGraphicsPixmapItem()
{
    this->scene = scene;
    QImage image = QImage(":/map/Assets/collision_square.png");
    this->block = this->scene->addPixmap(QPixmap::fromImage(image).scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    srand(time(0));
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
    std::vector< std::vector<int> > collision_bounds = {
        // 0
        {1,3,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,39},
        {1,2,18,37,39},
        {1,39},
        {1,39},
        {1,39},
        {1,3,4,25,39},
        {1,3,4,8,9,12,23,33,34,35,36,37,38,39},
        {1,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32},
        {1,11},
        {2,9,10,11},
        {2,3,9,10,11},
        // 11
        {2,7,8,11},
        {2,7,8,11},
        {2,11},
        {2,3,7,8,9,10,11},
        {3,7,8,9,10,11},
        {3,7,11,19,20,21,22,23,24,25},
        {3,7,11,19,25},
        {3,11,19,25},
        {3,11,18,25,31,32,33,38},
        {3,11,18,25,26,27,28,29,30,31,33,38},
        // 21
        {3,8,9,10,11,18,33,34,35,36,37,38},
        {1,2,3,8,18,38},
        {1,7,8,18,38},
        {1,2,3,7,18,19,20,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38},
        {3,7,20,24},
        {3,7,20,24},
        {3,7,20,24},
        {3,7,16,17,18,19,20,25},
        {3,7,16,25},
        {3,7,16,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39},
        //31
        {3,7,16,34,35,36,39},
        {3,7,8,9,10,11,12,13,14,15,16,17,18,19,36,39},
        {0,1,2,3,13,16,17,19,36,39},
        {3,10,11,18,19,36,39},
        {3,10,11,19,36,39},
        {3,19,36,39},
        {3,11,12,19,36,37,38,39},
        {3,11,12,16,17,18,19,36,39},
        {3,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,36,37,40},
        {3,19,20,21,22,23,24,25,26,27,28,29,30,31,36,37,40},
        // 41
        {3,40},
        {3, 40,41,42,43,44,45,46,47,48,49},
        {3},
        {3},
        {0,1,2,3},
        {40,41,42,43,44,45,46},
        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,46},
        {46,47,48,49},
        {}
    };
    for (int y = 0; y < collision_bounds.size(); y++) {
        for (int x = 0; x < collision_bounds[y].size(); x++) {
            Grid *g = new Grid(this->scene);
            g->block->setPos(collision_bounds[y][x]*32, y*32);
            this->scene->addItem(g);
        }
    }
}

bool Grid::encounterChance()
{
    // 1/20 chance to run into a wild pokemon. If random num is greater than 5, return. Else battle.
    if ((rand() % 100) + 1 > 5) return false;
    return true;
}

void Grid::encounter()
{
    QWidget *battle_window = new QWidget();
    battle_window->setFixedSize(600, 400);
    battle_window->show();
    //    battle_window->hide();
}
