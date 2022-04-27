#include <QKeyEvent>
#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>
#include <QDebug>
#include "Headers/player.h"
#include "Headers/sprite.h"

Player::Player(QGraphicsScene *scene): QGraphicsPixmapItem()
{
    this->x_pos = 1450; this->y_pos = 1300;
    this->scene = scene;
    this->sprite = new Sprite(QPixmap::fromImage(QImage(":/chars/Assets/player.png")), 35, 50);
    setPixmap(this->sprite->getSprite(this->sprite->getDownSprite(), this->sprite->getDownSpriteIndex()));
}

Player::~Player()
{
    delete this->scene; delete this->sprite;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    /* When a movement key is pressed, the program calls setPixmap() to update the direction the sprite
     * is facing to match the directional key pressed. Then the scene is updated by increasing or decreasing
     * its xy position corresponding to the direction.
     */
    switch (event->key()) {
        // Up movement key
        case Qt::Key_W:
            setPixmap(this->sprite->getSprite(this->sprite->getUpSprite(), this->sprite->getUpSpriteIndex()));
            if (this->y_pos == 0) break;
            if (!this->checkVerticalBounds()) {
                this->scene->setSceneRect(this->scene->sceneRect().x(),
                                          this->scene->sceneRect().y() - 10,
                                          this->scene->width(),
                                          this->scene->height()
                                          );
            }
            setPos(x(), y() - 10);
            this->y_pos -= 10;
            break;

        // Left movement key
        case Qt::Key_A:
            setPixmap(this->sprite->getSprite(this->sprite->getLeftSprite(), this->sprite->getLeftSpriteIndex()));
            if (this->x_pos == 0) break;
            if (!this->checkHorizontalBounds()) {
                this->scene->setSceneRect(this->scene->sceneRect().x() - 10,
                                          this->scene->sceneRect().y(),
                                          this->scene->width(),
                                          this->scene->height()
                                          );
            }
            setPos(x() - 10, y());
            this->x_pos -= 10;
            break;

        // Down movement key
        case Qt::Key_S:
            setPixmap(this->sprite->getSprite(this->sprite->getDownSprite(), this->sprite->getDownSpriteIndex()));
            if (this->y_pos == 1500-40) break;
            if (!this->checkVerticalBounds()) {
                this->scene->setSceneRect(this->scene->sceneRect().x(),
                                          this->scene->sceneRect().y() + 10,
                                          this->scene->width(),
                                          this->scene->height()
                                          );
            }
            setPos(x(), y() + 10);
            this->y_pos += 10;
            break;

        // Right movement key
        case Qt::Key_D:
            setPixmap(this->sprite->getSprite(this->sprite->getRightSprite(), this->sprite->getRightSpriteIndex()));
            if (this->x_pos == 1500-40) break;
            if (!this->checkHorizontalBounds()) {
                this->scene->setSceneRect(this->scene->sceneRect().x() + 10,
                                          this->scene->sceneRect().y(),
                                          this->scene->width(),
                                          this->scene->height()
                                          );
            }
            setPos(x() + 10, y());
            this->x_pos += 10;
            break;

        // Interact key
        case Qt::Key_Return:
            qDebug() << QString("interation initiated");
            break;

        // Breaks if a key not specified above is pressed.
        default: break;
    }
}

bool Player::checkVerticalBounds()
{
    qDebug() << this->y_pos;
    return (this->y_pos >= 1500-400 || this->y_pos <= 400);
}

bool Player::checkHorizontalBounds()
{
    return (this->x_pos >= 1500-400 || this->x_pos <= 400);
}
