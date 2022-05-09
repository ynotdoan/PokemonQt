#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMovie>
#include <QMediaPlayer>
//#include <QMediaPlaylist>

#include "Headers/player.h"
#include "Headers/boss.h"


namespace Ui
{
    class Game;
}

class Game: public QMainWindow
{
    Q_OBJECT

    Ui::Game *ui;
    QMovie *intro;
    QMediaPlayer *music_player;
   // QMediaPlaylist *playlist;
    Player *player;
    Boss *boss;

    bool checkVerticalBounds();
    bool checkHorizontalBounds();
    void addPlayer();
    void addBoss();

public:
    Game(QWidget *parent = 0);
    ~Game();
    void run();
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_intro_button_released();
    void on_Fight_released();
    void on_Quickattack_released();
    void on_shock_released();
    void on_ArceusHealth_valueChanged(int value);
    void on_Pikachuhealth_valueChanged(int value);
    void on_Run_released();
};

#endif // GAME_H
