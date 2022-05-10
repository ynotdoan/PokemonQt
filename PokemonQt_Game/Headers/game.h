#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMovie>
#include <QTimer>

#include "Headers/player.h"
#include "Headers/boss.h"
#include "Headers/musicplayer.h"

namespace Ui
{
    class Game;
}

class Game: public QMainWindow
{
    Q_OBJECT

    Ui::Game *ui;
    QMovie *intro;
    Player *player;
    Boss *boss;
    MusicPlayer mp;
    bool player_turn;

    bool checkVerticalBounds();
    bool checkHorizontalBounds();
    void addPlayer();
    void addBoss();
    void gameWin();
    void gameLoss();
    void initBattle();
    void initGame();
    void animatePokemon(bool player, int shift, int time);
    void dealDamage(bool player, std::string move);
    void setText(bool player, std::string move);

public:
    Game(QWidget *parent = 0);
    ~Game();
    void run();
    void keyPressEvent(QKeyEvent *event);

private slots:
    void arceusAttack();
    void on_intro_button_released();
    void on_Fight_released();
    void on_Quickattack_released();
    void on_shock_released();
    void on_Run_released();
    void on_YesRun_released();
    void on_NoRun_released();
    void on_Back_released();
    void on_GameOverYes_released();
    void on_GamveOverNo_released();
    void on_WinYes_released();
    void on_WinNo_released();
};

#endif // GAME_H
