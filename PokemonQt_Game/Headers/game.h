#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QMovie>

namespace Ui
{
    class Game;
}

class Game: public QMainWindow
{
    Q_OBJECT

    Ui::Game *ui;
    QMovie *intro;
/*
    QGraphicsScene *scene;
    Player *player;
    Grid *grid;
    Arceus *arc;
    std::vector< std::vector<Grid*> > grid_blocks;
*/
public:
    Game(QWidget *parent = 0);
    ~Game();
/*
    void setMap();
    void addMap();
    void run();
*/
private slots:
    void on_intro_button_released();
};

#endif // GAME_H
