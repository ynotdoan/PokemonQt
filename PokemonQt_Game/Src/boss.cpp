#include "Headers/boss.h"

Boss::Boss()
{
    this->arceus = QPixmap::fromImage(QImage(":/chars/Assets/arceus1.png"));
}

Boss::~Boss()
{

}

QPixmap Boss::getBoss(std::string name)
{
    // This function takes in a string name of a boss and returns its QPixmap.
    if (name == "Arceus") {
        return this->arceus;
    }
}
