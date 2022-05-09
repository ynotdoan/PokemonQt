#include <QMainWindow>
#include <QMovie>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>
#include <QImage>
#include <QPixmap>

#include "Headers/game.h"
#include "ui_game.h"

namespace Ui
{
    class Game;
}

Game::Game(QWidget *parent): QMainWindow(parent), ui(new Ui::Game)
{
    // Sets up UI
    this->ui->setupUi(this);

    this->mp.setMusic(QUrl("qrc:/sounds/Assets/Music/introSong.mp3"));

    // Creates new QMovie and loads it onto intro_screen qlabel.
    this->intro = new QMovie(":/map/Assets/introscreen.gif");
    this->ui->intro_scene->setMovie(intro);
    this->intro->start();
}

Game::~Game()
{
    delete this->intro; delete this->ui;
}

void Game::run()
{
    this->show(); // Shows the ui when called.
}

void Game::keyPressEvent(QKeyEvent *event)
{
    /* When a movement key is pressed, the program calls setPixmap() to update the direction
     * the sprite is facing to match the directional key pressed. Then the function checks
     * if the current xy positions are at the edge of the map. If so, then the player is not
     * able to advance in that direction. If the player is not at or in range of an edge of
     * the map, then the map is updated by increasing or decreasing its xy position
     * corresponding to the direction.
     */
    switch (event->key()) {
        // Up movement
        case Qt::Key_W:
            this->ui->p_sprite->setPixmap(this->player->getSprite(
                                            this->player->getUSprite(),
                                            this->player->getUSpriteIndex()
                                          ));
            if (this->ui->p_sprite->y() <= 80) {
                this->ui->content->setCurrentIndex(2);
                this->mp.setMusic(QUrl("qrc:/sounds/Assets/Music/battle.mp3"));
            }
            if (this->ui->p_sprite->y() == this->ui->map->y()) {
                break;
            } else if (!this->checkVerticalBounds()) {
                this->ui->map->move(this->ui->map->x(),
                                      this->ui->map->y()+8);
            }
            this->ui->p_sprite->move(this->ui->p_sprite->x(),
                                     this->ui->p_sprite->y()-8);
            break;

        // Down movement
        case Qt::Key_S:
            this->ui->p_sprite->setPixmap(this->player->getSprite(
                                            this->player->getDSprite(),
                                            this->player->getDSpriteIndex()
                                          ));
            if (this->ui->p_sprite->y() == this->ui->map->height()-this->ui->p_sprite->height()) {
                break;
            } else if (!this->checkVerticalBounds()) {
                this->ui->map->move(this->ui->map->x(),
                                      this->ui->map->y()-8);
            }
            this->ui->p_sprite->move(this->ui->p_sprite->x(),
                                     this->ui->p_sprite->y()+8);
            break;

        // Left movement
        case Qt::Key_A:
            this->ui->p_sprite->setPixmap(this->player->getSprite(
                                            this->player->getLSprite(),
                                            this->player->getLSpriteIndex()
                                          ));
            if (this->ui->p_sprite->x() == this->ui->map->x()) {
                break;
            } else if (!this->checkHorizontalBounds()) {
                this->ui->map->move(this->ui->map->x()-8,
                                      this->ui->map->y());
            }
            this->ui->p_sprite->move(this->ui->p_sprite->x()-8,
                                     this->ui->p_sprite->y());
            break;

        // Right movement
        case Qt::Key_D:
            this->ui->p_sprite->setPixmap(this->player->getSprite(
                                            this->player->getRSprite(),
                                            this->player->getRSpriteIndex()
                                          ));
            if (this->ui->p_sprite->x() == this->ui->map->width()) {
                break;
            } else if (!this->checkHorizontalBounds()) {
                this->ui->map->move(this->ui->map->x()+8,
                                      this->ui->map->y());
            }
            this->ui->p_sprite->move(this->ui->p_sprite->x()+8,
                                     this->ui->p_sprite->y());
            break;

        // If key pressed that does not match cases above, do nothing.
        default: break;
    }
}

/* CheckBound functions check whether or not the player is within range of an edge of the map.
 * The function checks if the player's x position is within 0 and 512/2 and if the player's
 * y position is within 0 and 800/2. If the player's xy coordinates are within those ranges,
 * the functions will return true and the map will not shift and only the player does.
 */
bool Game::checkVerticalBounds()
{
    return (this->ui->p_sprite->y() <= this->ui->map->y()+this->ui->World->height()/2 ||
            this->ui->p_sprite->y() >= (this->ui->map->height()-this->ui->World->height()/2));
}

bool Game::checkHorizontalBounds()
{
    return (this->ui->p_sprite->x() <= this->ui->map->x()+this->ui->World->width()/2 ||
            this->ui->p_sprite->x() >= this->ui->map->width()-this->ui->World->width()/2);
}

void Game::addPlayer()
{
    // Adds player sprite onto map.
    this->player = new Player();
    QPixmap sp = this->player->getSprite(player->getDSprite(), player->getDSpriteIndex());
    this->ui->p_sprite->setPixmap(sp);
}

void Game::addBoss()
{
    // Adds Boss sprite onto map.
    this->boss = new Boss();
    this->ui->a_sprite->setPixmap(boss->getBoss("Arceus"));
}

void Game::on_intro_button_released()
{
    // When player clicks and releases title screen, load all game components.
    this->ui->content->setCurrentIndex(1);
    this->mp.setMusic(QUrl("qrc:/sounds/Assets/Music/route.mp3"));
    this->addBoss();
    this->addPlayer();
}

void Game::on_Fight_released()
{
    qDebug() << "Fight";
    this->ui->menu->hide();
}


void Game::on_Quickattack_released()
{
    int Damage = rand()%(15-5 + 1) + 5;
    if(Damage >= this->ui->ArceusHealth->value()) {
        this->ui->ArceusHealth->setValue(0);
        if (this->ui->ArceusHealth->value() == 0) {
            this->ui->content->setCurrentIndex(3);
            this->gameWin();
        }
    }
    this->ui->ArceusHealth->setValue(this->ui->ArceusHealth->value()-Damage);
}


void Game::on_shock_released()
{
    int Damage = rand()%(25-10 + 1) + 10;
    if(Damage >= this->ui->ArceusHealth->value()) {
        //Damage = rand() % (this->ui->ArceusHealth->value() - 1 +1) + 1;
        this->ui->ArceusHealth->setValue(0);
        if (this->ui->ArceusHealth->value() == 0) {
            this->gameWin();
            this->ui->content->setCurrentIndex(3);
        }


    }
    qDebug()  << Damage;
    this->ui->ArceusHealth->setValue(this->ui->ArceusHealth->value()-Damage);
}

void Game::on_Run_released()
{
     this->ui->content->setCurrentIndex(1);
}

void Game::gameLoss(){
    QPixmap angrypikachu(":/chars/Assets/Angry-Pikachu.png");
    ui->p_loss->setPixmap(angrypikachu.scaled(300, 300, Qt::KeepAspectRatio));
}

void Game::gameWin(){
    this->mp.setMusic(QUrl("qrc:/sounds/Assets/Music/ending1.mp3"));
    QPixmap happypikachu(":/chars/Assets/PikachuHappySprite.png");
    ui->p_win->setPixmap(happypikachu.scaled(300,300, Qt::KeepAspectRatio));
}

