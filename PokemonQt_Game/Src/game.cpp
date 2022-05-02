#include <QPixmap>
#include <QImage>
#include <QGraphicsScene>
#include <vector>
#include <QDebug>
#include "Headers/game.h"
#include "Headers/player.h"

Game::Game(QWidget *parent)
{
    /* Calls all add functions to add game components into game.
     * First scene in created in setMap(), then collisions are added to mark bounds. Then the map image is added
     * on top of the collisions squares to hide them.
     */
    this->setMap();
    this->addMap();
    this->grid = new Grid(this->scene);
    this->grid->addCollisions();

//    this->addMap();

    this->player = new Player(this->scene);
    this->player->addPlayer();

    this->arc = new Arceus(this->scene);
    this->arc->addArceus();

}

Game::~Game()
{
    delete this->scene; delete this->player;
}

void Game::setMap()
{
    /* Set scene to xy position (800, 800), which is that bottom-right portion of the map where the
     * player begins. (800, 800) is the width x height of the image. The map is scaled to (1600, 1600)
     * so that the player's sprite does not look too big on the map. Set the window size to a fixed (800, 800).
     */
    this->scene = new QGraphicsScene();
    this->setScene(this->scene);
    // Hides scroll bars on the window.
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Fixed size so players can't resize window.
    this->setFixedSize(800, 800);

}

void Game::addMap()
{
    // Define background to be a QImage of overworld from resources.
    QImage background = QImage(":/map/Assets/overworld1.png");

    // Declare and define map as QPixmap of background.
    QPixmap map = QPixmap::fromImage(background);
    this->scene->setSceneRect(800, 800, 800, 800);
    this->scene->addPixmap(map.scaled(1600, 1600, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Game::run()
{
    show(); // Runs the game.
}
