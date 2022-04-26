#include <QPixmap>
#include <QImage>
#include "Headers/game.h"

Game::Game(QWidget *parent)
{

}

Game::~Game()
{
    delete this->scene;
}

void Game::initialize()
{
    this->scene = new QGraphicsScene(this);

    // Define background to be a QImage of overworld from resources.
    QImage background = QImage(":/map/Assets/overworld.png");

    // Declare and define map as QPixmap of background.
    QPixmap map = QPixmap::fromImage(background);

    this->scene->setSceneRect(0, 0, 400, 400);
    this->scene->addPixmap(map);
    setScene(this->scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::run()
{
    show();
}
