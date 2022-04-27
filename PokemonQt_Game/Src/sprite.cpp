#include "Headers/sprite.h"

Sprite::Sprite(QPixmap map, int width, int height): QGraphicsPixmapItem()
{
    // s is the amount of walk animations for a sprite for each direction.
    const int s = 4;

    // Allocating space for each sprite's direction to hold the walking animations.
    this->up_sprites = new QPixmap[s];
    this->down_sprites = new QPixmap[s];
    this->left_sprites = new QPixmap[s];
    this->right_sprites = new QPixmap[s];

    // Setting each index a different walk animation.
    this->up_sprites[0] = map.copy(15, 205, width, height);
    this->up_sprites[1] = map.copy(75, 205, width, height);
    this->up_sprites[2] = map.copy(140, 205, width, height);
    this->up_sprites[3] = map.copy(205, 205, width, height);
    this->down_sprites[0] = map.copy(15, 10, width, height);
    this->down_sprites[1] = map.copy(75, 10, width, height);
    this->down_sprites[2] = map.copy(140, 10, width, height);
    this->down_sprites[3] = map.copy(205, 10, width, height);
    this->left_sprites[0] = map.copy(15, 75, width, height);
    this->left_sprites[1] = map.copy(75, 75, width, height);
    this->left_sprites[2] = map.copy(140, 75, width, height);
    this->left_sprites[3] = map.copy(205, 75, width, height);
    this->right_sprites[0] = map.copy(15, 140, width, height);
    this->right_sprites[1] = map.copy(75, 140, width, height);
    this->right_sprites[2] = map.copy(140, 140, width, height);
    this->right_sprites[3] = map.copy(205, 140, width, height);

    // Defining the index for each direction to be 0, which is the initial stance.
    this->up_index = this->down_index = this->left_index = this->right_index = 0;
}

Sprite::~Sprite()
{
    delete this->up_sprites; delete this->down_sprites; delete this->left_sprites; delete this->right_sprites;
}

QPixmap Sprite::getSprite(QPixmap *sprites, int &index)
{
    // Set sprite to initial index.
    QPixmap sprite = sprites[index];
    // Increment index.
    this->updateSpriteIndex(index);
    return sprite;
}

void Sprite::updateSpriteIndex(int &index)
{
    // Increment index and find its remainder when divided by 4.
    // Use modulus 4 because there are 4 walking animations so the animation resets when index is grater than 4.
    index = (index + 1) % 4;
}

QPixmap* Sprite::getUpSprite()
{
    return this->up_sprites;
}

int& Sprite::getUpSpriteIndex()
{
    return this->up_index;
}

void Sprite::setUpSpriteIndex(int index)
{
    this->up_index = index;
}

QPixmap* Sprite::getDownSprite()
{
    return this->down_sprites;
}

int& Sprite::getDownSpriteIndex()
{
    return this->down_index;
}

void Sprite::setDownSpriteIndex(int index)
{
    this->down_index = index;
}

QPixmap* Sprite::getLeftSprite()
{
    return this->left_sprites;
}

int& Sprite::getLeftSpriteIndex()
{
    return this->left_index;
}

void Sprite::setLeftSpriteIndex(int index)
{
    this->left_index = index;
}

QPixmap* Sprite::getRightSprite()
{
    return this->right_sprites;
}

int& Sprite::getRightSpriteIndex()
{
    return right_index;
}

void Sprite::setRightSpriteIndex(int index)
{
    this->right_index = index;
}
