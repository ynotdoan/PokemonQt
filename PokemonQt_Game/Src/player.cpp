#include <QKeyEvent>
#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QDebug>
#include "Headers/player.h"
#include "Headers/sprite.h"

Player::Player(QGraphicsScene *scene): QGraphicsPixmapItem()
{
    this->scene = scene;
    this->sprite = new Sprite(QPixmap::fromImage(QImage(":/chars/Assets/player.png")), 35, 50);
    this->shape();
    setPixmap(this->sprite->getSprite(this->sprite->getDownSprite(), this->sprite->getDownSpriteIndex()));
}

Player::~Player()
{
    delete this->scene; delete this->sprite;
}

void Player::addPlayer()
{
    /* Add the player's sprite to the scene. Set the player's initial position to (1450, 1300), which is
     * the bottom-right of the map where the player will begin. The player is set to be focusable in-order
     * to control the sprite. If the player is not moving, try clicking directly on the player with the mouse
     * and keeping the mouse within the game's window.
     */
    this->setPos(1550, 1400); // 1550, 1400
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->scene->addItem(this);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    /* When a movement key is pressed, the program calls setPixmap() to update the direction the sprite
     * is facing to match the directional key pressed. Then the function checks if the current xy positions
     * are at the edge of the map, if so, then the player is not able to advance in that direction. If the
     * player is not at or in range of an edge of the map, then the scene is updated by increasing or decreasing
     * its xy position corresponding to the direction.
     */
    switch (event->key()) {
        // Up movement key
        case Qt::Key_W:
            setPixmap(this->sprite->getSprite(this->sprite->getUpSprite(), this->sprite->getUpSpriteIndex()));
            this->checkEncounter();
            if (this->y() == 0 || this->checkCollision()) {
                break;
            } else if (!this->checkVerticalBounds()) {
                this->scene->setSceneRect(this->scene->sceneRect().x(),
                                          this->scene->sceneRect().y() - 10,
                                          this->scene->width(),
                                          this->scene->height()
                                          );
            }
            setPos(x(), y() - 10);
            break;

        // Left movement key
        case Qt::Key_A:
            setPixmap(this->sprite->getSprite(this->sprite->getLeftSprite(), this->sprite->getLeftSpriteIndex()));
            this->checkEncounter();
            if (this->x() == 0 || this->checkCollision()) {
                break;
            } else if (!this->checkHorizontalBounds()) {
                this->scene->setSceneRect(this->scene->sceneRect().x() - 10,
                                          this->scene->sceneRect().y(),
                                          this->scene->width(),
                                          this->scene->height()
                                          );
            }
            setPos(x() - 10, y());
            break;

        // Down movement key
        case Qt::Key_S:
            setPixmap(this->sprite->getSprite(this->sprite->getDownSprite(), this->sprite->getDownSpriteIndex()));
            this->checkEncounter();
            if (this->y() == (this->scene->width()*2)-40 || this->checkCollision()) {
                break;
            } else if (!this->checkVerticalBounds()) {
                this->scene->setSceneRect(this->scene->sceneRect().x(),
                                          this->scene->sceneRect().y() + 10,
                                          this->scene->width(),
                                          this->scene->height()
                                          );
            }
            setPos(x(), y() + 10);
            break;

        // Right movement key
        case Qt::Key_D:
            setPixmap(this->sprite->getSprite(this->sprite->getRightSprite(), this->sprite->getRightSpriteIndex()));
            this->checkEncounter();
            if (this->x() == (this->scene->width()*2)-40 || this->checkCollision()) {
                break;
            } else if (!this->checkHorizontalBounds()) {
                this->scene->setSceneRect(this->scene->sceneRect().x() + 10,
                                          this->scene->sceneRect().y(),
                                          this->scene->width(),
                                          this->scene->height()
                                          );

            }
            setPos(x() + 10, y());
            break;

        // Interact key
        case Qt::Key_Return:
            qDebug() << QString("interation initiated");
            break;

        // If a key not specified above is pressed, program will move on until another key press is detected.
        default: break;
    }
}

/* CheckBound functions check whether or not the player is within range of an edge of the map. The function checks
 * if the xy positions are greater than 1100 or less than 400, and if either is true, function will return true so
 * the map's position will not shift anymore and the player will only move on screen until they hit an edge.
 * The player is centered at (400, 400).
 */
bool Player::checkVerticalBounds()
{
//    qDebug() << "y: " << this->y();
    return (this->y() > 1600-400 || this->y() < 400);
}

bool Player::checkHorizontalBounds()
{
//    qDebug() << "x: " << this->x();
    return (this->x() > 1600-400 || this->x() < 400);
}

bool Player::checkCollision()
{
    QList<QGraphicsItem*> items = this->collidingItems();
    items.removeLast(); // Remove last item because it is the player.
    for (const auto& item : items) {
        if (item->collidesWithItem(this)) {
            return true;
        }
    }
    return false;
}

void Player::checkEncounter()
{
    if (this->x() > 20*32 && this->x() < 36*32 && this->y() < 38*32 && this->y() > 31*32) {
        if (Grid::encounterChance()) {
            Grid::encounter();
        }
    }
    // Area for encountering Arceus.
    if (this->x() > 33*32 && this->y() > 1*32 && this->x() < 37*32 && this->y() < 4*32) {
        Grid::encounter();
    }
}
