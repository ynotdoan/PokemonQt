#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMovie>

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
};

#endif // GAME_H
