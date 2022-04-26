#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

class Game: public QGraphicsView
{
    Q_OBJECT

    QGraphicsScene *scene;

public:
    Game(QWidget *parent = 0);
    ~Game();

    void initialize();
    void run();
};

#endif // GAME_H
