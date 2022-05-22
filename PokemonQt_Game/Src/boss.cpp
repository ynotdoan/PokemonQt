#include "Headers/boss.h"

Boss::Boss()
{
    this->arceus = QPixmap::fromImage(QImage(":/chars/Assets/arceus1.png"));
}

Boss::~Boss()
{

}

QPixmap Boss::getBoss(QString name)
{
    // This function takes in a string name of a boss and returns its QPixmap.
    if (name == "Arceus") {
        return this->arceus;
    }
}

QString Boss::setBossMove(QString name)
{
    // Chooses a random number between 1 and 2 and returns one of two moves for a boss.
    int move = (rand() % 2) + 1;
    if (name == "Arceus") {
        if (move == 1) return "JD";
        else return "TA";
    }
}
