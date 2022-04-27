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

    this->scene->setSceneRect(700, 700, 800, 800);
    this->scene->addPixmap(map.scaled(1500, 1500, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setScene(this->scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 800);

    this->addPlayer();
}

Game::~Game()
{
    delete this->scene; delete this->player;
}

void Game::addPlayer()
{
    this->player = new Player(this->scene);
    this->player->setPos(1450, 1300);
    this->player->setFlag(QGraphicsItem::ItemIsFocusable);
    this->player->setFocus();
    this->scene->addItem(this->player);
}

void Game::run()
{
    show();
}
