#include "Headers/player.h"
#include "Headers/game.h"
#include "ui_game.h"

Player::Player()
{
    // Defining w x h for player sprite.
    this->width = 35; this->height = 50;

    // Define QImage for player sprite and make it a QPixmap.
    this->p_image = QImage(":/chars/Assets/Pikachu.png");
    QPixmap p_sprite = QPixmap::fromImage(this->p_image);

    // Initialize QPixmap sprites for each direction.
    this->u_sprites = new QPixmap[this->s];
    this->d_sprites = new QPixmap[this->s];
    this->l_sprites = new QPixmap[this->s];
    this->r_sprites = new QPixmap[this->s];

    // Setting each index a different walk animation.
    this->u_sprites[0] = p_sprite.copy(15, 205, this->width, this->height);
    this->u_sprites[1] = p_sprite.copy(75, 205, this->width, this->height);
    this->u_sprites[2] = p_sprite.copy(140, 205, this->width, this->height);
    this->u_sprites[3] = p_sprite.copy(205, 205, this->width, this->height);
    this->d_sprites[0] = p_sprite.copy(15, 10, this->width, this->height);
    this->d_sprites[1] = p_sprite.copy(75, 10, this->width, this->height);
    this->d_sprites[2] = p_sprite.copy(140, 10, this->width, this->height);
    this->d_sprites[3] = p_sprite.copy(205, 10, this->width, this->height);
    this->l_sprites[0] = p_sprite.copy(15, 75, this->width, this->height);
    this->l_sprites[1] = p_sprite.copy(75, 75, this->width, this->height);
    this->l_sprites[2] = p_sprite.copy(140, 75, this->width, this->height);
    this->l_sprites[3] = p_sprite.copy(205, 75, this->width, this->height);
    this->r_sprites[0] = p_sprite.copy(15, 140, this->width, this->height);
    this->r_sprites[1] = p_sprite.copy(75, 140, this->width, this->height);
    this->r_sprites[2] = p_sprite.copy(140, 140, this->width, this->height);
    this->r_sprites[3] = p_sprite.copy(205, 140, this->width, this->height);

    // Set each direction index to 0, which is the initial stance.
    this->u_index = this->d_index = this->l_index = this->r_index = 0;
}

Player::~Player()
{
    delete this->u_sprites; delete this->d_sprites;
    delete this->l_sprites; delete this->r_sprites;
}

QPixmap Player::getSprite(QPixmap *sprites, int &index)
{
    QPixmap sp = sprites[index];
    this->updateSprite(index);
    return sp;
}

void Player::updateSprite(int &index)
{
    index = (index + 1) % 4;
}

QPixmap *Player::getUSprite()
{
    return this->u_sprites;
}

int &Player::getUSpriteIndex()
{
    return this->u_index;
}

void Player::setUSpriteIndex(int index)
{
    this->u_index = index;
}

QPixmap *Player::getDSprite()
{
    return this->d_sprites;
}

int &Player::getDSpriteIndex()
{
    return this->d_index;
}

void Player::setDSpriteIndex(int index)
{
    this->d_index = index;
}

QPixmap *Player::getLSprite()
{
    return this->l_sprites;
}

int &Player::getLSpriteIndex()
{
    return this->l_index;
}

void Player::setLSpriteIndex(int index)
{
    this->l_index = index;
}

QPixmap *Player::getRSprite()
{
    return this->r_sprites;
}

int &Player::getRSpriteIndex()
{
    return this->r_index;
}

void Player::setRSpriteIndex(int index)
{
    this->r_index = index;
}
