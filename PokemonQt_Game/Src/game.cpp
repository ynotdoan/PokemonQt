#include <QPixmap>
#include <QImage>
#include <QGraphicsScene>
#include "Headers/game.h"
#include "Headers/player.h"

Game::Game(QWidget *parent)
{
    this->scene = new QGraphicsScene();

    // Define background to be a QImage of overworld from resources.
    QImage background = QImage(":/map/Assets/overworld.png");

    // Declare and define map as QPixmap of background.
    QPixmap map = QPixmap::fromImage(background);

    this->scene->setSceneRect(0, 0, 400, 400);
    this->scene->addPixmap(map);
    setScene(this->scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400, 400);

    this->addPlayer();
}

Game::~Game()
{
    delete this->scene; delete this->player;
}

void Game::addPlayer()
{
    this->player = new Player(this->scene);
    this->player->setPos(200, 200);
    this->player->setFlag(QGraphicsItem::ItemIsFocusable);
    this->player->setFocus();
    this->scene->addItem(this->player);
}

void Game::run()
{
    show();
}
