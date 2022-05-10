#include <QMainWindow>
#include <QMovie>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QTimer>

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
    this->initGame();
}

Game::~Game()
{
    delete this->intro; delete this->ui;
}

void Game::run()
{
    this->show(); // Shows the ui when called.
}

void Game::initGame()
{
    // Shows the intro screen in ui and sets player sprite and map to starting positions.
    this->ui->content->setCurrentIndex(0);
    this->ui->p_sprite->setGeometry(QRect(240, 744, 32, 50));
    this->ui->map->setGeometry(QRect(0, -288, 512, 800));
    // Set pokemons' healths to full
    this->ui->ArceusHealth->setValue(100);
    this->ui->Pikachuhealth->setValue(100);
    // Plays intro scene music.
    this->mp.setMusic(QUrl("qrc:/sounds/Assets/Music/introSong.mp3"));
    // Creates new QMovie and loads it onto intro_screen qlabel to show intro gif.
    this->intro = new QMovie(":/map/Assets/introscreen.gif");
    this->ui->intro_scene->setMovie(intro);
    this->intro->start();
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
            // If player's y-value is less than 80, start battle against Arceus and changing
            // ui scene to battle index. Change music to battle music.
            if (this->ui->p_sprite->y() <= 80) {
                this->initBattle();
                this->ui->content->setCurrentIndex(2);
                this->mp.setMusic(QUrl("qrc:/sounds/Assets/Music/battle.mp3"));
            } else if (this->ui->p_sprite->y() == this->ui->map->y()) {
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

void Game::initBattle()
{
    this->player_turn = true;
    // Hides all other battle options so all buttons don't appear at once.
    this->ui->FightMenu->hide();
    this->ui->RunMenu->hide();
    this->ui->BattleMenu->show();
}

void Game::animatePokemon(bool player, int shift, int time)
{
    if (player) {
        QTimer::singleShot(time, [=] {
            this->ui->pikachu->setGeometry(
            this->ui->pikachu->geometry().x() + shift,
            this->ui->pikachu->geometry().y(),
            this->ui->pikachu->geometry().width(),
            this->ui->pikachu->geometry().height()
            );
        });
    } else {
        QTimer::singleShot(time, [=] {
            this->ui->arceus->setGeometry(
            this->ui->arceus->geometry().x() + shift,
            this->ui->arceus->geometry().y(),
            this->ui->arceus->geometry().width(),
            this->ui->arceus->geometry().height()
            );
        });
    }
}

void Game::dealDamage(bool player, std::string move)
{
    int damage = 0;

    if (player) {
        if (move == "SK") {
            damage = rand()%(20) + 10;
        } else if (move == "QA") {
            damage = rand()%(10) + 5;
        }
        this->animatePokemon(true, 20, 500);
        this->animatePokemon(true, 10, 1000);
        this->animatePokemon(false, 5, 1100);
        this->animatePokemon(true, -10, 1200);
        this->animatePokemon(false, -5, 1300);
        this->animatePokemon(true, -20, 2000);
        if (damage >= this->ui->ArceusHealth->value()) {
            this->ui->ArceusHealth->setValue(0);
            this->gameWin();
        }
        this->ui->ArceusHealth->setValue(this->ui->ArceusHealth->value()-damage);
    } else {
        if (move == "JD") {
            damage = rand()%(30) + 10;
        } else if (move == "TA") {
            damage = rand()%(10) + 5;
        }
        this->animatePokemon(false, -20, 500);
        this->animatePokemon(false, -10, 1000);
        this->animatePokemon(true, -5, 1100);
        this->animatePokemon(false, 10, 1200);
        this->animatePokemon(true, 5, 1300);
        this->animatePokemon(false, 20, 2000);
        if (damage >= this->ui->Pikachuhealth->value()) {
            this->ui->Pikachuhealth->setValue(0);
            this->gameLoss();
        }
        this->ui->Pikachuhealth->setValue(this->ui->Pikachuhealth->value()-damage);
    }
    this->ui->FightMenu->hide();
    this->ui->BattleMenu->show();
}

void Game::arceusAttack()
{
    this->dealDamage(false, "TA");
    this->setText(false, "TA");
    this->player_turn = true;
}

void Game::setText(bool player, std::string move)
{
    QString text;
    if (player) {
        if (move == "QA") {
            text = "Pikachu used Quick Attack!";
        } else if (move == "SK") {
            text = "Pikachu used Shock!";
        }
    } else {
        if (move == "JD") {
            text = "Arceus used Judgement!";
        } else if (move == "TA") {
            text = "Arceus used Tackle!";
        }
    }
    this->ui->battle_text->setText(text);
}

void Game::on_intro_button_released()
{
    // When player clicks and releases title screen, load all game components.
    this->ui->content->setCurrentIndex(1);
    this->mp.setMusic(QUrl("qrc:/sounds/Assets/Music/route.mp3"));
    this->addPlayer();
    this->addBoss();
}

void Game::on_Fight_released()
{
    if (this->player_turn) {
        this->ui->BattleMenu->hide();
        this->ui->FightMenu->show();
    }
}

void Game::on_Quickattack_released()
{
    this->dealDamage(true, "QA");
    this->setText(true, "QA");
    this->player_turn = false;
    QTimer::singleShot(4000, this, SLOT(arceusAttack()));
}

void Game::on_shock_released()
{
    this->dealDamage(true, "SK");
    this->setText(true, "SK");
    this->player_turn = false;
    QTimer::singleShot(4000, this, SLOT(arceusAttack()));
}

void Game::on_Back_released()
{
    this->ui->FightMenu->hide();
    this->ui->BattleMenu->show();
}

void Game::on_Run_released()
{
    if (this->player_turn) {
        this->ui->BattleMenu->hide();
        this->ui->RunMenu->show();
    }
}

void Game::on_YesRun_released()
{
    // If user confirms they want to run from battle, the game state will
    // return them to the map.
    this->mp.setMusic(QUrl("qrc:/sounds/Assets/Music/route.mp3"));
    this->ui->content->setCurrentIndex(1);
}


void Game::on_NoRun_released()
{
    this->ui->RunMenu->hide();
    this->ui->BattleMenu->show();
}

void Game::gameLoss(){
    this->mp.setMusic(QUrl());
    QPixmap angrypikachu(":/chars/Assets/Angry-Pikachu.png");
    ui->p_loss->setPixmap(angrypikachu.scaled(300, 300, Qt::KeepAspectRatio));
    this->ui->win->hide();
    this->ui->loss->show();
    this->ui->content->setCurrentIndex(3);
}

void Game::gameWin(){
    this->mp.setMusic(QUrl("qrc:/sounds/Assets/Music/ending1.mp3"));
    QPixmap happypikachu(":/chars/Assets/PikachuHappySprite.png");
    ui->p_win->setPixmap(happypikachu.scaled(300,300, Qt::KeepAspectRatio));
    this->ui->loss->hide();
    this->ui->win->show();
    this->ui->content->setCurrentIndex(3);
}

void Game::on_GameOverYes_released()
{
    this->initGame();
}


void Game::on_GamveOverNo_released()
{
    QApplication::quit();
}

void Game::on_WinYes_released()
{
    this->initGame();
}


void Game::on_WinNo_released()
{
    QApplication::quit();
}

