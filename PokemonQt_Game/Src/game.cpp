#include <QPixmap>
#include <QImage>
#include <QGraphicsScene>
#include "Headers/game.h"
#include "Headers/player.h"

Game::Game(QWidget *parent)
{
    this->scene = new QGraphicsScene();

    // Define background to be a QImage of overworld from resources.
    QImage background = QImage(":/map/Assets/overworld1.png");

    // Declare and define map as QPixmap of background.
    QPixmap map = QPixmap::fromImage(background);

    /* Set scene to xy position (700, 700), which is that bottom-right portion of the map where the
     * player begins. (800, 800) is the width x height of the image. The map is scaled to (1500, 1500)
     * so that the player's sprite does not look too big on the map. Set the window size to a fixed (800, 800).
     */
    this->scene->setSceneRect(800, 800, 800, 800);
    this->scene->addPixmap(map.scaled(1600, 1600, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setScene(this->scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 800);

    this->addPlayer(); // Add the player's sprite.
    this->addCollisions();
}

Game::~Game()
{
    delete this->scene; delete this->player; delete this->collisions;
}

void Game::addPlayer()
{
    /* Add the player's sprite to the scene. Set the player's initial position to (1450, 1300), which is
     * the bottom-right of the map where the player will begin. The player is set to be focusable in-order
     * to control the sprite. If the player is not moving, try clicking directly on the player with the mouse
     * and keeping the mouse within the game's window.
     */
    this->player = new Player(this->scene);
    this->player->setPos(1550, 1400); // 1550, 1400
    this->player->setFlag(QGraphicsItem::ItemIsFocusable);
    this->player->setFocus();
    this->scene->addItem(this->player);
}

void Game::addCollisions()
{
    this->collisions = new Collisions(this->scene);
    this->collisions->collision_box->setPos(0, 0);
    this->scene->addItem(this->collisions);
    Collisions *collisions2 = new Collisions(this->scene);
    collisions2->collision_box->setPos(32, 0);
    this->scene->addItem(collisions2);
    Collisions *collisions3 = new Collisions(this->scene);
    collisions3->collision_box->setPos(32*3, 0);
    this->scene->addItem(collisions3);

}

void Game::run()
{
    show(); // Runs the game.
}
